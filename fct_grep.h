/*
 * fct_grep.h
 *
 *  Created on: 8 dec. 2012
 *      Author: Hugo
 */

#ifndef FCT_GREP_H_
#define FCT_GREP_H_

#include "arg_treatment.h"

int run_grep_onafile(char *afilepath, struct arguments *args);
int printline(char *aline,unsigned int line_count,long byte_offset,struct arguments *args, char *filepath);
int printcount(char *filepath, unsigned int match_count);

#endif /* FCT_GREP_H_ */
