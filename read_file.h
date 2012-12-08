/*
 * read_file.h
 *
 *  Created on: 2 nov. 2012
 *      Author: Hugo
 */

#ifndef READ_FILE_H_
#define READ_FILE_H_

/**
 * Open file with file path given
 * Return 0 when the file opens correctly, 1 for failure
 */
int open_file(char * file_path,FILE **pfile);

/**
 * Get the next line in the file
 * Return 0 when line is OK else 1 for error or EOF
 */
int get_line_file(FILE * file,char **line,size_t * size);
/**
 * Get the next line in the file -z null-data
 * Return 0 when line is OK else 1 for error or EOF
 */
int get_line_file_nd(FILE * file,char **line,size_t * size);

char *get_all_file(char *file_path);

#endif /* READ_FILE_H_ */
