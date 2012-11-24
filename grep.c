/*
 * grep.c
 *
 *  Created on: 2 nov. 2012
 *      Author: Hugo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arg_treatment.h"
#include "read_file.h"
#include "search.h"

int main(int argc, char **argv) {

	//treatment of argv check number
	struct arguments args;
	arg_init(&args);
	arg_treatment(&argc, argv, &args);

	//init pointer for open file
	FILE *currentfile = open_file(args.file_path);

	//default size for one line (debug value:50 , prod value: 1000)
	size_t defaultsize = 50;
	//init pointer for line buffer
	char *currentline = NULL;

	//execute options routine

	if (args.opt_i == 1) {
		str_to_lower(args.pattern);
	}

	//start the main loop
	int read_error_line;
	unsigned int match_count = 0, line_count = 0;
	char printout_n[200] = "";
	char printout_b[100] = "";

	if (args.opt_b) {
		snprintf(printout_b, 100, "%lu:", ftell(currentfile));
	}
	read_error_line =
			(!args.opt_z) ?
					get_line_file(currentfile, &currentline, &defaultsize) :
					get_line_file_nd(currentfile, &currentline, &defaultsize);
	while (!read_error_line) {
		if (args.opt_n)
			line_count++;
		if (search_simple_regex(currentline, args.pattern, &args)) {
			match_count++;
			if (args.opt_n) {
				snprintf(printout_n, 100, "%u:", line_count);
			}
			printf("%s%s\n", strcat(printout_n, printout_b), currentline);
		}

		if (args.opt_m && match_count >= args.opt_m_count)
			break;
		if (args.opt_b) {
			snprintf(printout_b, 100, "%lu:", ftell(currentfile));
		}
		read_error_line =
				(!args.opt_z) ?
						get_line_file(currentfile, &currentline, &defaultsize) :
						get_line_file_nd(currentfile, &currentline,
								&defaultsize);
	}
	//end the main loop

	free(currentline);
	currentline = NULL;
	arguments_delete(&args);
	return EXIT_SUCCESS;
}
