/*
 * read_file.c
 *
 *  Created on: 2 nov. 2012
 *      Author: Hugo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//def
#include "read_file.h"


int open_file(char *file_path,FILE ** file){

	*file = fopen (file_path, "r");

	if(file==NULL){
		printf("Impossible d'ouvrir le fichier\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}

int get_line_file(FILE ** file,char * line,size_t * size){

	//alloc mem for line
	/*
	line = calloc (*size,sizeof (char) );
	if(line == NULL){
	fprintf(stderr,"Impossible de créer cette merde en RAM\n");
	exit(EXIT_FAILURE);
	}
	*/

	//TODO implementer ligne plus grande que size et size auto
		if(fgets(line,*size,*file)==NULL){
			fclose(*file);
			return 1;
		}
		else{
			//verify all the line is read
			return 0;
		}

	return 0;
}
