#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "necessities_c.h"

char* get_time (char* string)
{
	char** to_take = split_string(string, ' ');
	char* date = malloc(11);
	char* month = malloc(3);
	int month_int;
	
	char month_take[12][4] = {"Jan" , "Fev" , "Mar", "Av", "Mai" , "Juin" , "Juil" , "Aou" , "Sept", "Oct", "Nov", "Dec"};
	for(int i = 0; i<12; i++) if (strstr(to_take[0], month_take[i])!=NULL) month_int =i+1;

	sprintf(month, "%02d", month_int);
	snprintf(date,11,"%s:%s:%s", "2023", month, to_take[1]);

	
	
	return date;
}
	


char* mlg_day (char* string)
{
	char* time= get_time(string);
	struct tm date;
	if(strptime(time, "%Y:%m:%d", &date) == NULL) return NULL;
	
	const char* day[] = {"Alahady", "Alatsinainy", "Talata", "Alarobia", "Alakamisy", "Zoma", "Sabotsy"};
	int nb_day= date.tm_wday;
	
	return day[nb_day];
}

char* mlg_month (char* string)
{
	char* time = get_time(string);
	struct tm date;
	if(strptime(time, "%Y:%m:%d", &date) == NULL) return NULL;
	
	const char* month[] = {"janoary", "febroary", "martsa", "aprily", "may", "jona" , "jolay", "aogositra", "septambra", "oktobra", "novambra", "desambra"};
	int nb_month = date.tm_mon;
	
	return month[nb_month];
}

char* mlg_date (char*string)
{
	char* day = mlg_day(string);
	char* month = mlg_month(string);
	char** to_take = split_string(string,' ');
	char* number_day = malloc(3);
	strcpy(number_day, to_take[1]);
	char* hour = malloc(20);
	strcpy(hour, to_take[2]);
	char* date = malloc(100);
	snprintf(date, 100, "%s %s %s %s %s", day, number_day, month, "2023", hour);
	return date;
}


	
