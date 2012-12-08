/*
 * run_through_dir.h
 *
 *  Created on: 25 nov. 2012
 *      Author: Hugo
 */

#ifndef RUN_THROUGH_DIR_H_
#define RUN_THROUGH_DIR_H_

#include <dirent.h>

short isDir(struct dirent *adir);
short isDirt(char *adir);
void recurse_dir(const char * dir_name,struct arguments *args);

#endif /* RUN_THROUGH_DIR_H_ */
