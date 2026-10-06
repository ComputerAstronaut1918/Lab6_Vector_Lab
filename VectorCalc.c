/*************************
* @file VectorCalc.c
* @breif 
* @author Harley Soto
* @date
*
* Compile: gcc -o vectorcal VectorCal.c
* @version 1.0
*************************/
#include <stdio.h>
#include <string.h>
#include "Interface.h"

/**
* @brief main - Takes any input argument such as help,exit,calc, etc.
* @param[in] argc takes input values 
* @param[in] argv takes input characters.
* @remark (Ad extraneous cases)
*/

int main(int argc, char *argv[]){
	if(argc == 2 && strcmp(argv[1], "-h") == 0){
		print_help();
		return 0;
	}
	if(argc > 1){
		fprintf(stdrr, "usage: %s [-h]\n",argv[0]);
		return 1;
	}
	runCalc();
	return 0;
}