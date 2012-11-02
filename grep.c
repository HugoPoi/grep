/*
 * grep.c
 *
 *  Created on: 2 nov. 2012
 *      Author: Hugo
 */


#include "arg_treatment.h"

int main(int argc, char **argv) {

	//treatment of argv check number
	struct arguments args;
	arg_treatment(&argc,&argv,&args);

	return 0;
}
