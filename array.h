/*************************
* @file 
* @breif 
* @author Harley Soto
* @date
*
* @version 1.0
*************************/
#ifndef ARRAY_H
#define ARRAY_H

#include "vector.h"

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
#define MAX_VECTORS 10

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark if the array reaches it defined 10 Vector max the function returns -1
*/
int addvector(vector v);

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark if the vector *out is not found the function returns -1
*/
int findvector(const char *name, vector *out);

/**
* @brief (Define Function)
*/
void clearvectors(void);

/**
* @brief counts the number of vectors in the array*
*/
int countvectors(void);

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark if a vector is out of range the function returns -1
*/	
int getvectors(int n, vector *out);

#endif