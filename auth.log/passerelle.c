#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "html_static.h"

int main () 
{
	header();
    char* query = getenv("QUERY_STRING");
   /*
    char* query = malloc(200);
	strcpy(query, "http://www.authlog.com/cgi-bin/passerelle.cgi?type=connexion&user=adrien&passwd=motdepasse");*/
	char* logtype_clim = strstr(query, "type=");
	logtype_clim += strlen("type="); 
	char* logtype = malloc(20);
	int i = 0;
	while(logtype_clim[i] != '\0' &&logtype_clim[i] != '&')
	{
		logtype[i] = logtype_clim[i];
		i++;
	}
	logtype[i] = '\0';
    
    char* user_clim = strstr(query, "user=");
	user_clim += strlen("user="); 
	char* user = malloc(100);
	i = 0;
	while(user_clim[i] != '\0' &&user_clim[i] != '&')
	{
		user[i] = user_clim[i];
		i++;
	}
	user[i] = '\0';
    
    char* password_clim = strstr(query, "passwd=");
	password_clim += strlen("passwd="); 
	char* password = malloc(100);
	i = 0;
	while(password_clim[i] != '\0' &&password_clim[i] != '&')
	{
		password[i] = password_clim[i];
		i++;
	}
	password[i] = '\0';

    FILE * info = fopen("info.csv", "a+");
    char* take = malloc(200);
    int cursor = 0;
	
    if(strstr(logtype, "inscription") != NULL)
    {
        fprintf(info, "%s:%s", user, password);
		redirection_form(user);
    }

    else if(strstr(logtype, "connexion") != NULL)
    {
        while(fgets(take,200,info) != NULL)
        {
            if(strstr(take,user) != NULL)
            {
				cursor ++;
                char* pass_key = malloc(100);
				strcpy(pass_key, take);
				pass_key+= strlen(user)+1;
				if(strcmp(pass_key, password) == 0)
				{
					redirection_form(user);
				}
				else
				{
					password_error();
				}
                
            }
        }
		if(cursor == 0)
		{
			password_error();
		}
    }


	ending();
    return 0;
}