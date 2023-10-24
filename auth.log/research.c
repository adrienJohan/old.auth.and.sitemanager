#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "necessities_c.h"
#include "mlg_date.h"


char** users_list () 
{
	FILE * user = fopen("/etc/passwd", "r");
	char* get_string = malloc(500);
	int file_line  = 0;
	while(fgets(get_string, 500 , user) != NULL)file_line++;
	fseek(user, 0 , SEEK_SET);
	char** all_users = malloc(file_line*sizeof(char*));
	for(int i = 0; i<file_line; i++) *(all_users+i) = malloc(500);
	int i = 0;
	while(fgets(get_string,500 , user) != NULL)
	{
		char** splited = split_string(get_string , ':');
		strcpy(all_users[i] , splited[0]);
		i++;
	}
	
	return all_users;
}

int verified_number () 
{
	FILE * user = fopen("/etc/passwd", "r");
	char* get_string = malloc(500);
	int file_line  = 0;
	while(fgets(get_string, 500 , user) != NULL)file_line++;
	fseek(user, 0 , SEEK_SET);
	return file_line;
}
	

char*** get_all_session (char* user) 
{
/*	
	char* query = getenv("QUERY_STRING");
	char* user = strstr(query, "user=");
	user += strlen("user="); */
	
	FILE * auth = fopen("/var/log/auth.log", "r");
	if (auth == NULL) {
    // Gérer l'erreur d'ouverture du fichier
    perror("Erreur d'ouverture du fichier auth.log");
    exit(1); // Ou une autre action appropriée
}

	char* get_line = malloc(1000);                                //on a ici le string qui contiendra ligne par ligne le fichier auth 
	int legit_session = 0;                                         //on y mettra le nombre de ligne où il y a les infos de session 
	
	while(fgets(get_line, 1000, auth) != NULL)                      //on traite ligne par ligne le fichier pour compter le nombre de session
	{ 
		char* sort_one = strstr(get_line, "session opened");
	
		char* sort_two = strstr(get_line, "session closed");

		if(sort_one != NULL || sort_two != NULL) 
		{
/*			
			char* sorted_one = strstr(sort_one, user);
			printf("%s\n", sorted_one);
			char* sorted_two = strstr(sort_two, user);
			printf("%s_n", sorted_two);
*/
			char* user_in_line = strstr(get_line, user);
			if(/*sorted_one  != NULL || sorted_two != NULL*/ user_in_line != NULL) { 
				legit_session ++;
			}
			
		}
	}

	fseek(auth, 0, SEEK_SET);
	char*** all_info = malloc((legit_session)*sizeof(char**));
	/*
	char* legit_string = malloc(3);                                              //on y mettra le nombre de session en char* pour fit dans le tableau de char***
	sprintf(legit_string, "%d", legit_session);                   //on transforme l'int en char*  
	*(all_info+0) = malloc(1*sizeof(char*));            // ce dernier tableau va contenir le nombre de session_legit ,autrement la taille du tableau à 3 dim 
	*(*(all_info+0)) = malloc(3);                         //3 suffirait dans la mesure où le nombre de session ne depasse pas 3 chiffres
	strcpy(all_info[0][0], legit_string);     
	*/  
	for(int i = 0; i<legit_session;i++)                                //on alloue ii la memoire pour all_info, string contenant tous les infos sur les sessions
	{
		*(all_info+i) = malloc(3* sizeof(char*));                                   // 3 refere aux infos à donner : user, etat session , date
		for(int j = 0; j<3; j++)*(*(all_info+i)+j) = malloc(100);
	}

	int cursor = 0;

	while(fgets(get_line, 500 , auth) != NULL)
	{

		char* sort_one = strstr(get_line, "session opened");
		char* sort_two = strstr(get_line, "session closed");
		if(sort_one != NULL || sort_two != NULL)
		{
			char* user_in_line = strstr(get_line, user);
			if(/*strstr(sort_one, user) != NULL || strstr(sort_two, user) != NULL*/ user_in_line != NULL)
			{
				char** split = split_string(get_line, ' ');
				char* date = mlg_date(get_line);
				strcpy(all_info[cursor][0], user);
				strcpy(all_info[cursor][1], split[7]);
				strcpy(all_info[cursor][2], date);
				cursor ++;
			}
		}
	}
	
	return all_info;                //le retour ici concerne le nombre de session d'un user recherché 
}

int legit_session_number (char* user)
{
	
	FILE * auth = fopen("/var/log/auth.log", "r");
	if (auth == NULL) {
    // Gérer l'erreur d'ouverture du fichier
    perror("Erreur d'ouverture du fichier auth.log");
    exit(1); // Ou une autre action appropriée
}

	char* get_line = malloc(1000);                                //on a ici le string qui contiendra ligne par ligne le fichier auth 
	int legit_session = 0;                                         //on y mettra le nombre de ligne où il y a les infos de session 
	
	while(fgets(get_line, 1000, auth) != NULL)                      //on traite ligne par ligne le fichier pour compter le nombre de session
	{ 
		char* sort_one = strstr(get_line, "session opened");
	
		char* sort_two = strstr(get_line, "session closed");

		if(sort_one != NULL || sort_two != NULL) 
		{
			char* user_in_line = strstr(get_line, user);
			if(/*sorted_one  != NULL || sorted_two != NULL*/ user_in_line != NULL) legit_session ++;
			
			
		}
	}

	fseek(auth, 0, SEEK_SET);
	return legit_session;
}
