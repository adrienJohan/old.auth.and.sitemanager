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
