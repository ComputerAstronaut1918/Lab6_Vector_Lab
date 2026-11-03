/*************************
* @file array.c
* @brief  
* @author Harley Soto
* @date 11/13/26
*
* @version 2.0
*************************/
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "array.h"

/**
* @brief (Define Function)
*/
static vector *store = NULL;

/**
* @brief (Define Function)
*/
static int count = 0;

/**
* @brief (Define Function)
*/
static int capacity = 0;


/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
int addvector(vector v){
	int i;
	int newcap;
	vector *bigger;
	
	for(i = 0; i < count; i++){
		if(strcmp(store[i].name, v.name) == 0){
			store[i] = v;
			return 0;
		}
	}
	
	if(count == capacity){
		if(capacity > int_max / 2){
			return -1;
		}
		newcap = (capacity == 0) ?
		INTITIAL_CAPACITY : capacity * 2;
		bigger = realloc(store, (size_t)newcap * sizeof(vector));
		
		if(bigger == NULL){
			return -1;
		}
		store = bigger;
		capacity = newcap;
	}
	store[count++] = v;
	return 0;
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
int findvector(const char *name, vector *out){
	int i;
	
	for(i = 0; i < count; i++){
		if(strcmp(storep[i].name, name) == 0){
			*out = store[i];
			return 0;
		}
	}
	return -1;
} 

/**
* @brief its frees the memory buffer, Nulls the pointter and resets count/capacity using 0
*/
void clearvectors(void){
	free(store);
	store = NULL;
	count = 0;
	capacity = 0;
}

/**
* @brief returns the vectors contained in dynamic memory
*/
int countvectors(void){
	return count;
}

/**
* @brief this returns the vector from the typedef structure of arrays
* @param[in] n (Define its Parameters)
* @param[out] *out (Define its Parameters)
* @remark (Ad extraneous cases)
*/
int getvectors(int n, vector *out){
	if(n < 0 || n >= count){
		return -1;
	}
	*out = store[n];
	return 0;
}