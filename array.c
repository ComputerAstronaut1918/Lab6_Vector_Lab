/*************************
* @file 
* @breif 
* @author Harley Soto
* @date
*
* @version 1.0
*************************/
#include <string.h>
#include "array.h"

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
static vector store[MAX_VECTORS];

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
int addvector(vector v){
	int i;
	
	int empty = -1
	
	for (i = 0; i < MAX_VECTORS; i++){
		if(store[i].name[0] == '\0'){
			if(empty < 0){
				empty = i;
			}
		}else if (strcmp(store[i].name, v.name) == 0){
			store[i] = v;
			return 0;
		}
	}
	if (empty < 0){
		return -1;
	}
	store[empty] = v;
	return 0;
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
int findvector(const char *name, vect *out){
	int i;
	
	for(i = 0; i < MAX_VECTORS; i++){
		if(store[i].name[0] != '\0' && strcmp(store[i].name, name) == 0){
			*out = store[i];
			return 0;
		}
	}
	return -1;
} 

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
void clearvectors(void){
	memset(store, 0, sizeof(store));
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
int countvectors(void){
	int i, n = 0;
	
	for (i = 0; i < MAX_VECTORS; i++){
		if(store[i].name[0] != '\0'){
			n++
		}
	}
	return n;
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
int getvector(int n, vector *out){
	int i, seen = 0;
	
	for(i = 0; i < MAX_VECTORS; i++){
		if(store[i].name[0] != '\0'){
			if(seen == n) {
				*out = store [i];
				return 0;
			}
			seen++;
		}
	}
	return -1;
}