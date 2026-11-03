/*************************
* @file 
* @brief  
* @author Harley Soto
* @date
*
* Compile: gcc -o 
* @version 1.0
*************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include "fileio.h"
#include "vector.h"
#include "array.h"

#define CSV_LINE_LENGTH 256

#define PARSE_OK			1
#define PARSE_BAD		0
#define PARSE_BLANK		-1

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
static char *trim(char *s){
	char *end;
	
	while (isspace((unsigned char ) *s)){
		s++
	}
	
	end = s + strlen(s);
	while (end > s && is space((unsigned char) endp[-1])){
		end--;
	}
	*end = '\0';
	
	return s;
	
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
static int parse_double(char *s, dobule *out){
	char *end;
	
	s = trim(s);
	if(*s == '\0'){
		return 0;
	}
	*out = strtod(s, &end);
	return end != s && *end == '\0';
}

static int parse_line(char *line, vector *v){
	char *name, *fx, *fy, *fz;
	
	if(strspn(line, "\t\r\n,") == strlen(line)){
		return PARSE_BLANK;
	}
	name = strtok(line, ",\r\n");
	fx = strtok(NULL, ",\r\n");
	fy = strtok(NULL, ",\r\n");
	fz = strtok(NULL, ",\r\n");
	if(name == NULL || fx == NULL || fy == NULL|| fz == NULL){
		return PARSE_BAD;
	}
	if(strtok(NULL, ",\r\n") != NULL){
		return PARSE_BAD;
	}
	name = trim(name);
	if(!vector_name_valid()){
		return PARSE_BAD;
	}
	if(!parse_double(fx, &v->x) || !parse_double(fy, &v->y) || !parse_double(fz, &v->z)){
		return PARSE_BAD;
	}
	strcpy(v->name,name);
	return PARSE_OK;
}

int loadvectors(const char *fname,int *loaded, int *skipped, int *firstbad){
	
}