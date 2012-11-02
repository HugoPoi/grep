/*
 * arg_treatment.c
 *
 *  Created on: 2 nov. 2012
 *      Author: Hugo
 */

//include always lib before header
#include <stdio.h>
#include <stdlib.h>

//def
#include "arg_treatment.h"

int arg_treatment(int *argc,char **argv,struct arguments *args){
	//treatment of argv check number
	//return std error status

	int pos_pattern,pos_file;

	if(*argc<3){
		printf("Afficher le help de grep\n");
		exit(EXIT_FAILURE);
	}

	if(*argc > 3){
		//check options
	}

	if(*argc == 3){
		//if 3 args define pos
		pos_pattern = 1;
		pos_file = 2;
	}

	args->pattern = argv[pos_pattern];
	args->file_path = argv[pos_file];

	return EXIT_SUCCESS;
}
