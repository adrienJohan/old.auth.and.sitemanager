#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "html_static.h"

int main () 
{
    header();
    title_form();
    char* query = getenv("QUERY_STRING");
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
    if(strstr(logtype,"connexion") != NULL)
    {
       signin_form(); 
    }
    else if(strstr(logtype, "inscription") != NULL)
    {
        signup_form();
    }

    ending();
    return 0;
}


