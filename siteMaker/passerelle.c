#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libgen.h>
#include "html_statics.h"

void config (char*servname, char*admin, char*document,char*cgi);
char* documentRoot (char* document);
void ip_holder (char* ip, char* servname);
char* r_admin(char* str);
char* extractHostname(char* url);

int main () 
{
    header();
    char* query = getenv("QUERY_STRING");
    
  
	
    char* servname_clim = strstr(query, "servername=");
	servname_clim += strlen("servername="); 
	char* servname = malloc(100);
	int i = 0;
	while(servname_clim[i] != '\0' && servname_clim[i] != '&')
	{
		servname[i] = servname_clim[i];
		i++;
	}
	servname[i] = '\0';

	char* admin_clim = strstr(query, "serveradmin=");
	admin_clim += strlen("serveradmin="); 
	char* admin = malloc(100);
	i = 0;
	while(admin_clim[i] != '\0' && admin_clim[i] != '&')
	{
		admin[i] = admin_clim[i];
		i++;
	}
	admin[i] = '\0';

	char* document_clim = strstr(query, "documentroot=");
	document_clim += strlen("documentroot="); 
	char* document = malloc(200);
	i = 0;
	while(document_clim[i] != '\0' && document_clim[i] != '&')
	{
		document[i] = document_clim[i];
		i++;
	}
	document[i] = '\0';

    char* ip_clim = strstr(query, "ip=");
	ip_clim += strlen("ip="); 
	char* ip = malloc(100);
	i = 0;
	while(ip_clim[i] != '\0' && ip_clim[i] != '&')
	{
		ip[i] = ip[i];
		i++;
	}
	ip[i] = '\0';


	char* cgi_clim = strstr(query, "cgi=");
	cgi_clim += strlen("cgi="); 
	char* cgi = malloc(10);
	i = 0;
	while(cgi_clim[i] != '\0' && cgi_clim[i] != '&')
	{
	    cgi[i] = cgi_clim[i];
		i++;
	}
	cgi[i] = '\0';

    char* real_document = documentRoot(document);
    char* real_admin = r_admin(admin);
    config(servname,real_admin, real_document, cgi);
    ip_holder(ip, servname);
    site_status();
    ending();
    return 0;
}


void config (char*servname, char*admin, char*document,char*cgi)
{
    char* directory = malloc(100);
    strcpy(directory, "/etc/apache2/sites-available/");
    char* hostname = extractHostname(servname);
    strcat(directory, hostname);
    strcat(directory,".conf");
    FILE*conf = fopen(directory, "a+");
    fprintf(conf, "<VirtualHost *:80>\n");
    fprintf(conf , "    ServerAdmin %s\n" , admin);
    fprintf(conf , "    DocumentRoot %s\n", document);
    if(strcmp(cgi, "oui") == 0) fprintf(conf, " ScriptAlias /cgi-bin/ %s\n", document);
    fprintf(conf,  "    <Directory %s>\n", document);
    if(strcmp(cgi, "non") == 0)
    {
        fprintf(conf,  "        Options Indexes FollowSymlinks\n");
        fprintf(conf,  "        AllowOverride None\n");
        fprintf(conf,  "        Require all granted\n");

    }
    else if(strcmp(cgi, "oui") == 0)
    {
        fprintf(conf,  "        Options Indexes FollowSymlinks ExecCGI\n");
        fprintf(conf , "        AddHandler cgi-script .cgi\n");
        fprintf(conf,  "        AllowOverride None\n");
        fprintf(conf,  "        Require all granted\n");
    }
    fprintf(conf,"    </Directory>\n");
    fprintf(conf, " ErrorLog ${APACHE_LOG_DIR}/error.log\n");
    fprintf(conf, " CustomLog ${APACHE_LOG_DIR}/access.log combined\n");
    fprintf(conf, "</VirtualHost>\n");

    fclose(conf);

}

char* documentRoot (char* document)
{

    char* result = malloc((strlen(document) + 1) * sizeof(char));

    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    strcpy(result, document);
    char* ptr = result;

    while ((ptr = strstr(ptr, "%2F")) != NULL) {
        memmove(ptr + 1, ptr + 3, strlen(ptr + 2));
        *ptr = '/';
    }

    return result;
}


void ip_holder (char* ip, char* servname)
{
    FILE*hosts = fopen("/etc/hosts", "a+");
    fprintf(hosts,"%s   %s\n",ip, servname);
    fclose(hosts);
}



char* r_admin(char* str) {
    // Allocate memory with extra space for potential changes
    char* result = malloc((strlen(str) + 1) * sizeof(char));

    // Check for allocation failure
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    strcpy(result, str);
    char* ptr = result;

    while ((ptr = strstr(ptr, "%40")) != NULL) {
        // Move characters to replace "%40" with "@"
        memmove(ptr + 1, ptr + 3, strlen(ptr + 2));
        *ptr = '@';
    }

    return result;
}

char* extractHostname(char* url) {
    char* urlCopy = strdup(url);
    urlCopy += strlen("www.");
    char* hostname = malloc(50);
    int i  = 0;
    while(urlCopy[i] != '.')
    {
        hostname[i] = urlCopy[i];
        i++;
    }
    hostname[i] = '\0';
    return hostname;
}