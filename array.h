/*************************
* @file array.h
* @brief a definer file for array with Defined constants
* @author Harley Soto
* @date 10/15/26
*
* @version 1.0
*************************/
#ifndef ARRAY_H
#define ARRAY_H

#include "vector.h"

/**
* @brief This is the defined max of Vectors to hold as noted in the Lab-procedures
*/
#define MAX_VECTORS 10

/**
* @brief this fucntion adds a vector to the array list
* @param[in] v gives the listed Struct of the V vector to add to the array
* @remark if the array reaches it defined 10 Vector max the function returns -1
*/
int addvector(vector v);

/**
* @brief this will find vectors to calculate, listed in the created vector array
* @param[in] *name this receives a 32 char limit name defined in the vector array 
* @param[out] *out return of vector array out
* @remark if the vector *out is not found the function returns -1
*/
int findvector(const char *name, vector *out);

/**
* @brief this function clears the vectors store in array
*/
void clearvectors(void);

/**
* @brief counts the number of vectors in the array*
*/
int countvectors(void);

/**
* @brief this will find vectors to list, listed in the created vector array
* @param[in] n is the number of vectors wanting to pull from the array 
* @remark if a vector is out of range the function returns -1
*/	
int getvectors(int n, vector *out);

#endif