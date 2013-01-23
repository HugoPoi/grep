/*
 * fct_grep.h
 *
 *  Created on: 8 déc. 2012
 *      Author: Hugo
 */

#ifndef FCT_GREP_H_
#define FCT_GREP_H_

#include "arg_treatment.h"

int run_grep_onafile(char *afilepath, struct arguments *args);
int printline(char *aline,unsigned int line_count,long byte_offset,struct arguments *args, char *filepath);

#endif /* FCT_GREP_H_ */
