/*
 * arg_treatment.c
 *
 *  Created on: 2 nov. 2012
 *      Author: Hugo
 */

//include always lib before header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//def
#include "arg_treatment.h"

int arg_init(struct arguments *args) {

	args->opt_E = 0;
	args->opt_F = 0;
	args->opt_G = 0;
	args->opt_P = 0;
	args->opt_e = 0;
	args->opt_f = 0;
	args->opt_i = 0;
	args->opt_w = 0;
	args->opt_x = 0;
	args->opt_z = 0;
	args->opt_s = 0;
	args->opt_v = 0;
	args->opt_V = 0;
	args->opt_help = 0;

	args->opt_m = 0;
	args->opt_b = 0;
	args->opt_n = 0;
	args->opt_H = 0;
	args->opt_h = 0;
	args->opt_o = 0;
	args->opt_q = 0;
	args->opt_a = 0;
	args->opt_I = 0;
	args->opt_d = 0;
	args->opt_D = 0;
	args->opt_R = 0;
	args->opt_L = 0;
	args->opt_l = 0;
	args->opt_c = 0;
	args->opt_T = 0;
	args->opt_Z = 0;

	args->opt_B = 0;
	args->opt_A = 0;
	args->opt_C = 0;
	args->opt_U = 0;
	args->opt_u = 0;

	return 1;
}

int arg_treatment(int *argc, char **argv, struct arguments *args) {
	//treatment of argv check number
	//return std error status

	int pos_pattern, pos_file, i = 0;

	for (i = 1; i < *argc; i++) {

		//option --help
		if (strcmp(argv[i], "--help") == 0) {
			args->opt_help = 1;
			fprintf(stdout,"help of grep\n");
			exit(2);
		}

		//option --version
		if (strcmp(argv[i], "--version") == 0 || strcmp(argv[i], "-V") == 0) {
			args->opt_V = 1;
			fprintf(stdout,"version of grep\n");
			exit(2);
		}

		//option -f=
		if (strncmp(argv[i], "-f=", 3) == 0) {
			args->opt_f = 1;
			args->opt_f_file = &argv[i][3];
		}
		//option --file=
		if (strncmp(argv[i], "--file=", 7) == 0) {
			args->opt_f = 1;
			args->opt_f_file = &argv[i][7];
		}

	}

	if (*argc < 3) {
		fprintf(stdout,"help of grep\n");
		exit(2);
	}

	if (*argc == 3) {
		//if 3 args define pos
		pos_pattern = 1;
		pos_file = 2;
	}

	args->pattern = argv[pos_pattern];
	args->file_path = argv[pos_file];

	return EXIT_SUCCESS;
}
