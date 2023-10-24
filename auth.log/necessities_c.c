#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** split_string ( char* string , char limit ) 
{
	int space_number = 0 , string_number = 0;               //on y mettra le nombre d'espace et le nombre de "mot" de la chaine
	for(int i = 0; i<strlen(string); i++) if(string[i] == limit) space_number++;
	string_number = space_number + 1;
	char** container = malloc(string_number*sizeof(char*));    //on va y mettre un par un les "mots"
	for(int i = 0; i<string_number; i++) *(container+i) = malloc(1000);
	int i = 0, j = 0 , k = 0; 
	for(i= 0; i<strlen(string); i++)
	{
		if(string[i] != limit) 
		{
			container[j][k] = string[i];
			
			k++;
		}
		else
		{
			container[j][k] = '\0';
			k = 0;
			j++;
			
		}
	}
	return container;
}

/*int stringToInteger (char* string)                          ///fonction pour transformer un char* en entier
{
	int number=0;
    int i=0, j=0;
	    for(i=strlen(string)-1; i>=0;i--){                 //on fait une base 10 pour avoir l'entier
		number += (string[i]-48)*pow(10,j);                     
		j++;
	}
	return number;
}
*/
