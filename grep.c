/*
 * grep.c
 *
 *  Created on: 2 nov. 2012
 *      Author: Hugo
 */
#include <stdio.h>
#include <stdlib.h>

#include "arg_treatment.h"
#include "read_file.h"
#include "search.h"

int main(int argc, char **argv) {

	//treatment of argv check number
	struct arguments args;
	arg_init(&args);
	arg_treatment(&argc,argv,&args);

	//init pointer for open file
	FILE *currentfile=open_file(args.file_path);


	//default size for one line (debug value:50 , prod value: 1000)
	size_t defaultsize = 50;
	//init pointer for line buffer
	char *currentline=NULL;

	//execute options routine

	if(args.opt_i == 1){
		str_to_lower(args.pattern);
	}


	while(!get_line_file(currentfile,&currentline,&defaultsize)){
		if(search_simple_regex(currentline,args.pattern,&args)){
			printf("%s\n",currentline);
		}
	}

	free(currentline);
	currentline = NULL;
	arguments_delete(&args);
	return EXIT_SUCCESS;
}
