/*
 * arg_treatment.h
 *
 *  Created on: 2 nov. 2012
 *      Author: Hugo
 */

#ifndef ARG_TREATMENT_H_
#define ARG_TREATMENT_H_

struct arguments
{
   char *pattern;
   char *file_path;

};

int arg_treatment(int *argc,char **argv,struct arguments *args);

#endif /* ARG_TREATMENT_H_ */
