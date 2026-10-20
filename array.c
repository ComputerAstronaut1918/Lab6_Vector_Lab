/*************************
* @file array.c
* @brief  
* @author Harley Soto
* @date 10/15/26
*
* @version 1.0
*************************/
#include <string.h>
#include "array.h"

/**	
* @brief creates the array structure for the vectors to be stored in
*/
static vector store[MAX_VECTORS];

/**
* @brief adds a vector v struct to the array
* @param[in] v (Define its Parameters)
* @remark in the case that a vector empty/DNE it will return a -1 to interface.
*/
int addvector(vector v){
	int i;
	
	int empty = -1;
	
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
* @brief finds the given vector and returns its x,y,z values
* @param[in] *name the inputted name of vector
* @param[out] *out (Define its Parameters)
* @remark in the case a vector DNE it will return -1 to Interface
*/
int findvector(const char *name, vector *out){
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
* @brief clears the stored array structure of all arrays
* @remark (Ad extraneous cases)
*/
void clearvectors(void){
	memset(store, 0, sizeof(store));
}

/**
* @brief counts the number of vectors to ensure it does not pass the predefined limit of 10
* @remark (Ad extraneous cases)
*/
int countvectors(void){
	int i, n = 0;
	
	for (i = 0; i < MAX_VECTORS; i++){
		if(store[i].name[0] != '\0'){
			n++;
		}
	}
	return n;
}

/**
* @brief this returns the vector from the typedef structure of arrays
* @param[in] n (Define its Parameters)
* @param[out] *out (Define its Parameters)
* @remark (Ad extraneous cases)
*/
int getvectors(int n, vector *out){
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