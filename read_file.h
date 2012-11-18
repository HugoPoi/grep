/*
 * read_file.h
 *
 *  Created on: 2 nov. 2012
 *      Author: Hugo
 */

#ifndef READ_FILE_H_
#define READ_FILE_H_

FILE *open_file(char * file_path);

/**
 * Get the next line in the file
 * Return 0 when line is OK else 1
 */
int get_line_file(FILE * file,char *line,size_t * size);

#endif /* READ_FILE_H_ */
