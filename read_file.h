/*
 * read_file.h
 *
 *  Created on: 2 nov. 2012
 *      Author: Hugo
 */

#ifndef READ_FILE_H_
#define READ_FILE_H_

int open_file(char * file_path,FILE ** file);
int get_line_file(FILE ** file,char * line,size_t * size);

#endif /* READ_FILE_H_ */
