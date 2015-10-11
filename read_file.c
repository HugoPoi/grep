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

int open_file(char * file_path,FILE **pfile) {

	*pfile = fopen(file_path, "rb");

	if (*pfile == NULL ) {
		fprintf(stderr,"Impossible d'ouvrir le fichier\n");
		return 1;
	}

	return 0;
}

int get_line_file(FILE * file, char **line, size_t * size) {

	//alloc mem for line
	if (*line == NULL ) {
		*line = calloc(*size, sizeof(char));
	}

	if (*line == NULL ) {
		fprintf(stderr,"Impossible de créer cette merde en RAM\n");
		exit(EXIT_FAILURE);
	}

	if (fgets(*line, *size, file) == NULL ) {
		return 1;
	} else {
		//verify all the line is read
		char *endline = strchr(*line, '\n');

		if (endline != NULL ) {
			/* remove \n */
			*endline = '\0';
		} else {

			/* else, read the all line */
			if (!feof(file)) {
				char c;
				size_t maxsize = *size;
				size_t currentsize = *size;
				while ((c = fgetc(file)) != '\n' && c != EOF) {
					currentsize++;
					/* if overflow realloc x2 the buffer line*/
					if (currentsize > maxsize - 1) {
						maxsize = maxsize +100;
						*line = (char *) realloc(*line, maxsize * sizeof(char));
						if (*line == NULL ) {
							int dodo;
								fprintf(stderr,"Impossible de creer cette merde en RAM\n");
								scanf("%d",&dodo);
								dodo = 2 ;
								exit(EXIT_FAILURE);
						}
					}
					*(*line + currentsize - 2) = c;
				}
				*(*line + currentsize - 1) = '\0';
				*size = maxsize;
			}

		}
	}

	return 0;
}

int get_line_file_nd(FILE * file, char **line, size_t * size) {

	if (feof(file)) {
		return 1;
	}
	//alloc mem for line
	if (*line == NULL ) {
		*line = calloc(*size, sizeof(char));
	}

	if (*line == NULL ) {
		fprintf(stderr,"Impossible de creer cette merde en RAM\n");
		exit(EXIT_FAILURE);
	}
	char c;
	size_t maxsize = *size;
	size_t currentsize = 0;
	while ((c = fgetc(file)) != '\0' && c != EOF) {
		currentsize++;
		/* if overflow realloc x2 the buffer line*/
		if (currentsize > maxsize - 1) {
			maxsize = maxsize * 2;
			*line = realloc(*line, maxsize * sizeof(char));
		}
		*(*line + currentsize - 1) = c;
	}
	*(*line + currentsize) = '\0';
	*size = maxsize;
	return 0;
}

char *get_all_file(char *file_path) {

	FILE *file = NULL;
	if(open_file(file_path,&file)){
		exit(EXIT_FAILURE);
	}
	size_t size = 50;
	char c;
	char *line = calloc(size, sizeof(char));
	;
	size_t maxsize = size;
	size_t currentsize = 0;
	while ((c = fgetc(file)) != EOF) {
		currentsize++;
		/* if overflow realloc x2 the buffer line*/
		if (currentsize > maxsize - 1) {
			maxsize = maxsize * 2;
			line = realloc(line, maxsize * sizeof(char));
		}
		line[currentsize - 1] = c;
	}
	line[currentsize] = '\0';
	size = maxsize;
	fclose(file);
	return line;
}

