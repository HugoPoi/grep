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
	FILE * myfile=NULL;

	open_file(args.file_path,&myfile);

	//init tampon for lines
	//TODO dynamic size line for read a line go to read_file.c, just use a pointer
	size_t defaultsize = 50;
	char * myline;//[defaultsize];

	while(!get_line_file(&myfile,myline,&defaultsize)){
		if(search_simple_regex(myline,args.pattern)){
			//TODO add a \n after ends line.
			printf("%s\n",myline);
		}
	}

	free(myline);
	myline = NULL;

	return EXIT_SUCCESS;
}
