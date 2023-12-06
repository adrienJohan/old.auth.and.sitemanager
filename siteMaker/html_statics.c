#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void header () 
{
	printf("content-type: text/html\n\n");
	
	printf("<html>\n"
		   "<head><meta charset=UTF-8></head>\n"
		   "<body>\n");
}

void ending () 
{
	printf("\n</body>\n");
	printf("</html>\n");
}

void signin_form () 
{
	printf("<div>\n"
           "\t<table>\n"
           "\t\t<tr><td><p>connexion</p></td></tr>\n"
           "\t\t<tr>\n"
           "\t\t\t<td>\n"
           "\t\t\t<form action =àremplir method = get >\n" 
		   "\t\t\t<input type=hidden name=type value=connexion>\n"
           "\t\t\t<label>user:</label> <input type = text name = user><br><label>password:</label><input type = password name = passwd><input type = submit value =connexion>\n"
           "\t\t\t</form>\n"
           "\t\t\t</td>\n"
           "\t\t</tr>\n"
           "\t\t</table>\n"
   		   "</div>\n");
}

void signup_form () 
{
	printf("<div>\n"
           "\t<table>\n"
           "\t\t<tr><td><p>inscription</p></td></tr>\n"
           "\t\t<tr>\n"
           "\t\t\t<td>\n"
           "\t\t\t<form action =àremplir method = get >\n" 
		   "\t\t\t<input type=hidden name=type value=inscription>\n"
           "\t\t\t<label>user:</label> <input type = text name = user><br><label>password:</label><input type = password name = passwd><input type = submit value =s'inscrire>\n"
           "\t\t\t</form>\n"
           "\t\t\t</td>\n"
           "\t\t</tr>\n"
           "\t\t</table>\n"
   		   "</div>\n");
}




void title_form() 
{
	printf("<div>\n"
           "\t<table>\n"
           "\t\t<tr>\n"
		   "\t\t\t<td width = 1920px height = 80px bgcolor= #000000><p align = center style = font-family: Arial><font color = #FFFFFF size =5 ><b>LINUX&nbsp;SITE&nbsp;MANAGER</b></font></p></td>\n"
           "\t\t</tr>\n"
           "\t</table>\n"
    	   "</div>\n");	
}


void redirection_form(char* user)
{
	printf("<div>\n"
    "\t<p> Bienvenue %s</p>\n"
    "\t<a href=àremplir>Entrer dans le site</a>\n"
    "</div>\n", user);
}

void password_error()
{
	printf("<div>\n"
	"\t<p> mauvais mot de passe ou mauvais utilisateur</p>\n"
	"\t<a href=àremplir>retour à l'acceuil</a>\n"
	"</div>");
}


void site_status()
{
    printf("<div>\n"
           "\t<p> Voulez-vous activer le site?</p>\n"
           "\t<form action=http://www.sitemanager.com/cgi-bin/main.cgi method=get>\n"
           "\t\t<input type=submit value=oui>\n"
           "\t\t<input type=submit value=non\n"
           "\t</form>\n"
           "</div>"
    );
}
