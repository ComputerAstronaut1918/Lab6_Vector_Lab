/*************************
* @file interface.c
* @breif 
* @author Harley Soto
* @date
*
* @version 1.0
*************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <interface.h>

static void print_vector(const char *name, vect v){
	printf("%s = %g %g %g\n", name, v.x, v.y, v.z);
}

/**
* @brief prints a simple usage message to console to assist in proper input and other commands.
*/
void print_help(void){
	printf(
		"VectorCalc - a minimal vector calculator (w/ 3 component vectors)\n"
		"VectorCalc [-h]\n"
		"Commands - *Spaces are required around '=' and operators*:\n"
		""
		""
		"list"
		"clear"
		"help"
		"quit"
		"\n"
		"up to %d vectors may be stored at once.\n, MAX_VECTORS"
	);
}
