/*
 * read_file.c
 *
 *  Created on: 2 nov. 2012
 *      Author: Hugo
 */


#include <stdio.h>
#include <stdlib.h>

//def
#include "read_file.h"


int open_file(char *file_path,FILE *file){

	file = fopen (file_path, "r");

	if(file==NULL){
		printf("Impossible d'ouvrir le fichier");
		exit(EXIT_FAILURE);
	}

	return 0;
}

int get_line_file(FILE *file,char *line,int *size){


	fgets(line,sizeof(line),file);
	return 0;
}
