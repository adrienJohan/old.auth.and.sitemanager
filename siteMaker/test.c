#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

char* admin(char* str);
char* extractHostname(const char* url);

int main() {

    char* url = "www.adrien.com";
    char* extract = extractHostname(url);
    printf("%s\n", extract);
    return 0;
}


char* extractHostname(const char* url) {
    char* urlCopy = strdup(url);
    char* hostname = strdup(basename(urlCopy));
    return hostname;
}

/*

    //voici le documentroot  %2Fhome%2Fdls

    char* real_document = malloc(200);
    int j = 0;
    for(int i = 0; i<strlen(document);i++)
    {
        if(document[i] != '%' && document[i] != '2' && document[i] != 'F')
        {
            real_document[j] = document[i];
            j++;
        }
        else if(document[i] == '%')
        {
            real_document[j] = '/';
            j++;
        }

    }
    real_document[j] = '\0';

    return real_document;
    */

