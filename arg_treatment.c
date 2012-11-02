/*
 * arg_treatment.c
 *
 *  Created on: 2 nov. 2012
 *      Author: Hugo
 */

#include <stdio.h>

int arg_treatment(int* argc,char*** argv){
	//treatment of argv check number
	if(*argc<3){
		printf("Afficher le help de grep\n");
		return 1;
	}

	if(*argc > 3){
		//check options
	}

	return 0;
}
