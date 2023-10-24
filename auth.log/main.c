#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "necessities_c.h"
#include "mlg_date.h"
#include "html_static.h"
#include "page_necessity.h"
#include "research.h"


int main () 
{
	header();
	//research_form();	
	char* query = getenv("QUERY_STRING");
	char* user_clim = strstr(query, "user=");
	user_clim += strlen("user="); 
	char* user = malloc(20);
	int i = 0;
	while(user_clim[i] != '\0' &&user_clim[i] != '&')
	{
		user[i] = user_clim[i];
		i++;
	}
	user[i] = '\0';
	
	int user_number = verified_number();
	int cursor= 0;
	char** verified_users = users_list();
	for(int i = 0; i<user_number;i++)
	{
		if(strstr(verified_users[i], user) != NULL) cursor++;
	}
	if(cursor == 0)
	{
		non_user_case();
	}
	
	else
	{
		
		char*** all_session = get_all_session(user);
		int line_number = legit_session_number(user);

		static_title();
        int sessions_per_page = 10;
        int current_page = 1;
        char* page_param = strstr(query, "page=");
        if (page_param) {
            page_param += strlen("page=");
            current_page = atoi(page_param);
        }

        int start_session = (current_page - 1) * sessions_per_page;
        int end_session = start_session + sessions_per_page;

        for (int i = start_session; i < line_number && i < end_session; i++) {
            one_line_form(all_session[i][0], all_session[i][1], all_session[i][2]);
        }

        // bouton pagination
        printf("<div class='pagination'>\n");
        for (int page = 1; page <= (line_number + sessions_per_page - 1) / sessions_per_page; page++) {
            if (page == current_page) {
                printf("<span class='current_page'>%d</span>\n", page);
            } else {
                printf("<a href='main.cgi?user=%s&page=%d'>%d</a>\n", user, page, page);
            }
        }
        printf("</div>\n");

        printf("\t\t</table>\n");
    }

    ending();
		 
	
	return 0; 

}
