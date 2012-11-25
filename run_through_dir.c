/*
 * run_through_dir.c
 *
 *  Created on: 25 nov. 2012
 *      Author: Hugo
 */

#include <stdio.h>
#include <dirent.h>

#ifndef WIN32
    #include <sys/types.h> //if build on unix sys use types.h for telldir
#endif

//def
#include "run_through_dir.h"

short isDir(struct dirent *adir){
	DIR *ndir = NULL;
	if((ndir=opendir(adir->d_name))==NULL){
		return 0;
	}
	else{
		closedir(ndir);
		return 1;
	}
}
