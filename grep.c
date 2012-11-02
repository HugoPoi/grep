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

int main(int argc, char **argv) {

	//treatment of argv check number
	struct arguments args;
	arg_treatment(&argc,argv,&args);

	printf("%s;%s\n",args.pattern,args.file_path);

	FILE *myfile=NULL;
	open_file(args.file_path,myfile);

	int size = 256;
	char line[size];
	get_line_file(myfile,line,&size);
	fclose(myfile);
	printf("%s\n",line);

	return EXIT_SUCCESS;
}
