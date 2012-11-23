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
		fclose(file);
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
						maxsize = maxsize * 2;
						*line = realloc(*line, maxsize * sizeof(char));
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

char *get_all_file(char *file_path) {

	FILE *file = open_file(file_path);
	size_t size = 50;
	char c;
	char *line = calloc(size, sizeof(char));;
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

