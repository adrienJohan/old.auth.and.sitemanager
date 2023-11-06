#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void header () 
{
	printf("content-type: text/html\n\n");
	
	printf("<html>\n"
			"\t<head><meta charset=UTF-8></head>\n"
			"\t<body>\n");
}


void static_title () 
{
	printf("\t\t<table align= center border=font-family\n"
		   "\t\t\t<tr height = 50px>\n"
		   "\t\t\t\t<td  width =200px  bgcolor= #000000>\n"
		   "\t\t\t\t\t<p align = center style = font-family:Arial> <font color = #FFFFFF size = 5> <b>USER</b></font></p>\n"
		   "\t\t\t\t</td>\n"
		   "\t\t\t\t<td  width =200px  bgcolor= #000000>\n"
		   "\t\t\t\t\t<p align = center style = font-family:Arial> <font color = #FFFFFF size = 5> <b>SESSION</b></font></p>\n"
		   "\t\t\t\t</td>\n"
		   "\t\t\t\t<td  width =500px  bgcolor= #000000>\n"
		   "\t\t\t\t\t<p align = center style = font-family:Arial> <font color = #FFFFFF size = 5> <b>DATE</b></font></p>\n"
		   "\t\t\t\t</td>\n"
		   "\t\t\t</tr>\n");
}

void ending () 
{
	printf("\n</body>\n");
	printf("</html>\n");
}



void non_user_case()
{
	printf("\t\t<table align center>\n"
		   "\t\t\t<tr>\n"
		   "\t\t\t\t <td><p align = center>cet utilisateur n'existe pas, veuillez refaire une recherche ici - </p></td>\n"
		   "\t\t\t\t <td><a href =http://www.authlog.com/front_form.html> recherche </a></td>\n"
		   "\t\t\t </tr>\n"
		   "\t\t</table>\n"
		   );
}


void signin_form () 
{
	printf("<div>\n"
           "\t<table>\n"
           "\t\t<tr><td><p>connexion</p></td></tr>\n"
           "\t\t<tr>\n"
           "\t\t\t<td>\n"
           "\t\t\t<form action = http://www.authlog.com/cgi-bin/passerelle.cgi method = get >\n" 
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
           "\t\t\t<form action = http://www.authlog.com/cgi-bin/passerelle.cgi method = get >\n" 
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
		   "\t\t\t<td width = 1920px height = 80px bgcolor= #000000><p align = center style = font-family: Arial><font color = #FFFFFF size =5 ><b>LINUX&nbsp;PHYSICAL&nbsp;SESSIONS</b></font></p></td>\n"
           "\t\t</tr>\n"
           "\t</table>\n"
    	   "</div>\n");	
}


void redirection_form(char* user)
{
	printf("<div>\n"
    "\t<p> Bienvenue %s</p>\n"
    "\t<a href=http://www.authlog.com/front_form.html>Entrer dans le site</a>\n"
    "</div>\n", user);
}

void password_error()
{
	printf("<div>\n"
	"\t<p> mauvais mot de passe ou mauvais utilisateur</p>\n"
	"\t<a href=http://www.authlog.com/acceuil.html>retour à l'acceuil</a>\n"
	"</div>");
}