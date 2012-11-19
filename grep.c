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
	arg_treatment(&argc,argv,&args);

	//init pointer for open file
	FILE *myfile=open_file(args.file_path);


	//default size for one line (debug value:50 , prod value: 1000)
	size_t defaultsize = 50;
	//init pointer for line buffer
	char *myline=NULL;

	while(!get_line_file(myfile,&myline,&defaultsize)){
		if(search_simple_regex(myline,args.pattern)){
			printf("%s\n",myline);
		}
	}

	free(myline);
	myline = NULL;
	return EXIT_SUCCESS;
}
