/*
 * run_through_dir.c
 *
 *  Created on: 25 nov. 2012
 *      Author: Hugo
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#ifndef WIN32
#include <sys/types.h> //if build on unix sys use types.h for telldir
#endif

//def
#include "run_through_dir.h"

short isDir(struct dirent *adir) {
	DIR *ndir = NULL;
	if ((ndir = opendir(adir->d_name)) == NULL ) {
		return 0;
	} else {
		closedir(ndir);
		return 1;
	}
}

short isDirt(char * adir){
	DIR *ndir = NULL;
		if ((ndir = opendir(adir)) == NULL ) {
			return 0;
		} else {
			closedir(ndir);
			return 1;
		}
}

/* List the files in "dir_name". */

void recurse_dir(const char * dir_name) {
	DIR * d;

	char abs_path[PATH_MAX];//TODO dynamic alloc for buf with length of dir_name+d_name

	/* Open the directory specified by "dir_name". */

	d = opendir(dir_name);

	/* Check it was opened. */
	if (!d) {
		fprintf(stderr, "Cannot open directory '%s': %s\n",dir_name, strerror (errno));
		exit (EXIT_FAILURE);
	}
	while (1) {
		struct dirent * entry;
		const char * d_name;

		/* "Readdir" gets subsequent entries from "d". */
		entry = readdir(d);
		if (!entry) {
			/* There are no more entries in this directory, so break
			 out of the while loop. */
			break;
		}
		d_name = entry->d_name;

		//TODO here insert the grep input

		/* Print the name of the file and directory. */
		printf("%s/%s\n", dir_name, d_name);

		sprintf(abs_path,"%s/%s", dir_name, d_name);

		/* See if "entry" is a subdirectory of "d". */

		if (isDirt(abs_path)) { //(entry->d_type & DT_DIR) maybe use this for unix system

			/* Check that the directory is not "d" or d's parent. */

			if (strcmp(d_name, "..") != 0 && strcmp(d_name, ".") != 0) {
				int path_length;
				char path[PATH_MAX];

				path_length = snprintf(path, PATH_MAX, "%s/%s", dir_name,
						d_name);
				printf("%s\n", path);
				if (path_length >= PATH_MAX) {
					fprintf(stderr, "Path length has got too long.\n");
					exit (EXIT_FAILURE);
				}
					/* Recursively call "list_dir" with the new path. */
				recurse_dir(path);
			}
		}
	}
	/* After going through all the entries, close the directory. */
	if (closedir(d)) {
		fprintf(stderr, "Could not close '%s': %s\n",
		dir_name, strerror (errno));
		exit (EXIT_FAILURE);
	}
}
