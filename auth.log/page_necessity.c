#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void research_form () 
{
	printf("\t\t<table align= left bgcolor = #FFFFFF>\n"
		   "\t\t\t<tr>\n"
		   "\t\t\t\t<td>\n"
		   "\t\t\t\t\t<form action=/cgi-bin/auth.log/main.cgi method= get>\n" 
		   "\t\t\t\t\t\t<tr>\n"
		   "\t\t\t\t\t\t\t<td> <label>USER</label> </td>\n"
		   "\t\t\t\t\t\t\t<td> <input type = text name = user value = user> </td>\n"
		   "\t\t\t\t\t\t\t<td>  <input type=submit value = confirm> </td>\n"
		   "\t\t\t\t\t\t</tr>\n"
		   "\t\t\t\t\t</form>\n"
		   "\t\t\t\t</td>\n"
		   "\t\t\t</tr>\n"
		   "\t\t</table>\n");
}



/*void number_button_form (int d) 
{
	printf("\t\t\t\t<td>\n"
		   "\t\t\t\t\t<form action = /cgi-bin/ method = get> <input type = hidden name = page value = %d> <input type =  submit value =%d> </form>\n"
     	   "\t\t\t\t</td>\n");
}
*/

void one_line_form (char* user, char* session, char* date) 
{
	printf(
		   "\t\t\t<tr height = 50px>\n"
		   "\t\t\t\t<td  width =200px  bgcolor= #FFFFFF>\n"
		   "\t\t\t\t\t<p align = center style = font-family:Arial>  <font color = #000000 size = 5> <b> %s </b> </font> </p>\n"
		   "\t\t\t\t</td>\n"
		   "\t\t\t\t<td width =200px bgcolor= #FFFFFF>\n"
		   "\t\t\t\t\t<p align = center style = font-family:Arial>  <font color = #000000 size = 5> <b> %s </b> </font> </p>\n"
		   "\t\t\t\t</td>\n"
		   "\t\t\t\t<td width =500px bgcolor= #FFFFFF>\n"
		   "\t\t\t\t\t<p align = center style = font-family:Arial>  <font color = #000000 size = 5> <b> %s </b> </font> </p>\n"
		   "\t\t\t\t</td>\n"
		   "\t\t\t</tr>\n"
			, user, session, date);
}


	
