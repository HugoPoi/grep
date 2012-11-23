/*
 * search.c
 *
 *  Created on: 9 nov. 2012
 *      Author: Hugo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "search.h"

int search_simple_regex(char *line,char *pattern,struct arguments *args){

	/*if(args->opt_i == 1){
		str_to_lower(line);
	}*/
	if(strstr(line,pattern)==NULL){
		return 0;
	}

	return 1;
}

void str_to_lower(char *line){
	int i=0;
	while(line[i]!='\0'){
		if(line[i]>='A' && line[i]<='Z'){
			line[i]+=32;
		}
		i++;
	}
}
