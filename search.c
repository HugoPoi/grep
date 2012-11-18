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

int search_simple_regex(char *line,char *pattern){

	if(strstr(line,pattern)==NULL){
		return 0;
	}
	return 1;
}
