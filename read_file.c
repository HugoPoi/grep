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

FILE *open_file(char *file_path) {

	FILE *file = fopen(file_path, "r");

	if (file == NULL ) {
		printf("Impossible d'ouvrir le fichier\n");
		exit(EXIT_FAILURE);
	}

	return file;
}

int get_line_file(FILE * file, char *line, size_t * size) {

	//alloc mem for line
	if (line == NULL ) {
		line = calloc(*size, sizeof(char));
	}

	if (line == NULL ) {
		fprintf(stderr,"Impossible de créer cette merde en RAM\n");
		exit(EXIT_FAILURE);
	}

	if (fgets(line, *size, file) == NULL ) {
		fclose(file);
		return 1;
	} else {
		//verify all the line is read
		//debug
		printf("line:%s##",line);
		char *endline = strchr(line, '\n');

		if (endline != NULL ) {
			/* remove \n */
			*endline = '\0';
		} else {

			/* sinon, on lit tous les caracteres restants */
			if (!feof(file)) {/*
				char c;
				size_t maxsize=*size;//(50)
				size_t currentsize=*size;//(50)
				while ((c = fgetc(file)) != '\n' && c != EOF) {
					currentsize++;//(51)
					if(currentsize>maxsize-1){
						maxsize = maxsize*2;//(100)
						line = realloc(line,maxsize * sizeof(char));
					}
					//printf("%c,%d,%d\n",c,currentsize-2,maxsize);
					printf("%s\n",line);
					//*line[currentsize-2]=c;
				}
				//*line[currentsize-1]='\0';
				*size = maxsize;
				//Debug
				//printf("OverFlow:%s\n", *line);
			*/}

		}
	}

	//debug
	//printf("readok:%s\n",*line);

	return 0;
}
