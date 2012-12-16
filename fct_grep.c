/*
 * fct_grep.c
 *
 *  Created on: 8 déc. 2012
 *      Author: Hugo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_file.h"
#include "search.h"
#include "fifo_context.h"

#include "fct_grep.h"

int run_grep_onafile(char *afilepath, struct arguments *args) {

	FILE *file = NULL;

	if (open_file(afilepath, &file)) {
		exit(EXIT_FAILURE);
	}

	//default size for one line (debug value:50 , prod value: 1000)
	size_t defaultsize = 50;
	//init pointer for line buffer
	char *currentline = NULL;

	//start the main loop
	int read_error_line;
	unsigned int match_count = 0, line_count = 0;
	long byte_offset = 0;
	long current_byte_offset = 0;
	fpos_t current_endline_pos;
	Fifo_linecontext *before_line_pos = NULL;
	//fpos_t before_line_pos;
	//unsigned int count_B = 0;
	unsigned int line_print_count = 0;

	fifo_savenextline(&before_line_pos, file, args->opt_B_lines); //save the pos before for context
	if (args->opt_b)
		byte_offset = ftell(file);
	read_error_line =
			(!args->opt_z) ?
					get_line_file(file, &currentline, &defaultsize) :
					get_line_file_nd(file, &currentline, &defaultsize);
	while (!read_error_line) {
		fgetpos(file, &current_endline_pos); //save the start of the nextline
		if (args->opt_n)
			line_count++;
		if (search_simple_regex(currentline, args->pattern, args)) {
			match_count++;
			if (!(args->opt_B == 1 || args->opt_C == 1 || args->opt_A == 1)) {

				printline(currentline, line_count, byte_offset, args);

			} else {
				//Print with context
				if(args->opt_B == 1 || args->opt_C == 1){
				current_byte_offset = ftell(file);
				fsetpos(file, before_line_pos->data);
				line_print_count = 0;
				read_error_line =
						(!args->opt_z) ?
								get_line_file(file, &currentline,
										&defaultsize) :
								get_line_file_nd(file, &currentline,
										&defaultsize);
				while ((line_print_count <= (args->opt_B_lines))
						&& !read_error_line) {

					line_print_count++;

					printline(currentline, line_count, byte_offset, args);
					if (current_byte_offset == ftell(file))
						break;
					read_error_line =
							(!args->opt_z) ?
									get_line_file(file, &currentline,
											&defaultsize) :
									get_line_file_nd(file, &currentline,
											&defaultsize);
				}
				}
				if(args->opt_A == 1) printline(currentline, line_count, byte_offset, args);
				if(args->opt_C == 1 || args->opt_A == 1){
				line_print_count = 0;
				read_error_line =
						(!args->opt_z) ?
								get_line_file(file, &currentline,
										&defaultsize) :
								get_line_file_nd(file, &currentline,
										&defaultsize);
				while ((line_print_count < (args->opt_A_lines))
						&& !read_error_line) {

					line_print_count++;

					printline(currentline, line_count, byte_offset, args);

					read_error_line =
							(!args->opt_z) ?
									get_line_file(file, &currentline,
											&defaultsize) :
									get_line_file_nd(file, &currentline,
											&defaultsize);
				}
				}
				fsetpos(file, &current_endline_pos);

			}
		}

		if (args->opt_m && match_count >= args->opt_m_count)
			break;
		if (args->opt_b)
			byte_offset = ftell(file);

		if (args->opt_B == 1 || args->opt_C == 1) {
			fifo_savenextline(&before_line_pos, file, args->opt_B_lines);
		}

		read_error_line =
				(!args->opt_z) ?
						get_line_file(file, &currentline, &defaultsize) :
						get_line_file_nd(file, &currentline, &defaultsize);
	}
	//end the main loop
	fifo_clear(&before_line_pos);
	fclose(file);
	free(currentline);
	currentline = NULL;

	return 0;
}

int printline(char *aline, unsigned int line_count, long byte_offset,
		struct arguments *args) {
	char printout_n[100] = "";
	char printout_b[100] = "";
	//Simple Print out without context
	if (args->opt_n) {
		snprintf(printout_n, 100, "%u:", line_count);
	}
	if (args->opt_b) {
		snprintf(printout_b, 100, "%lu:", byte_offset);
	}
	printf("%s%s%s%s%s\n", (args->opt_H) ? args->file_path : "",
			(args->opt_H) ? ":" : "", printout_n, printout_b, aline);
	//End Simple Print out without context
	return 1;
}
