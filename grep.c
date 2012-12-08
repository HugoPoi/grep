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
#include "run_through_dir.h"
#include "fct_grep.h"
#include "search.h"

int main(int argc, char **argv) {

	//treatment of argv check number
	struct arguments args;
	arg_init(&args);
	arg_treatment(&argc, argv, &args);

	//execute options routine

	if (args.opt_i == 1) {
		str_to_lower(args.pattern);
	}

	if (args.opt_d_action == 2) {
		recurse_dir(args.file_path,&args);
	} else {
		run_grep_onafile(args.file_path, &args);
	}

	arguments_delete(&args);

	return EXIT_SUCCESS;
}
