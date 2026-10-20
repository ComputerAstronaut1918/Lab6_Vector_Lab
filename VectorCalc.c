/*************************
* @file VectorCalc.c
* @brief Execuatable file for the Vector Calculator
* @author Harley Soto
* @date 10/15/26
*
* Compile: gcc -o vectorcal VectorCal.c vector.c array.c interface.c 
* @note - calculator is programmed with Noise when a error Occurs at each Print - Statement
* @version 1.0
*************************/
#include <stdio.h>
#include <string.h>
#include "interface.h"

/**
* @brief main - Takes any input argument such from terminal to execute in Interface.c
* @param[in] argc takes input values 
* @param[in] argv takes input array of characters.
*/

int main(int argc, char *argv[]){
	if(argc == 2 && strcmp(argv[1], "-h") == 0){
		print_help();
		return 0;
	}
	if(argc > 1){
		fprintf(stderr, "usage: %s [-h]\n",argv[0]);
		return 1;
	}
	runCalc();
	return 0;
}