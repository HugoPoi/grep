/*
 * search.h
 *
 *  Created on: 9 nov. 2012
 *      Author: Hugo
 */

#ifndef SEARCH_H_
#define SEARCH_H_

// include for the struct arguments
#include "arg_treatment.h"

int search_simple_regex(char *line,char *pattern,struct arguments *args);

/**
 * Depreciated only for testing
 */
void str_to_lower(char *line);

#endif /* SEARCH_H_ */
