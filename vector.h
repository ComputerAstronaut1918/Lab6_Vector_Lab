/*************************
* @file 
* @breif 
* @author Harley Soto
* @date
*
* @version 1.0
*************************/
#ifndef VECTOR_H
#define VECTOR_H

#define NAME_LENGTH 32

typedef struct{
	char name[NAME_LENGTH];
	double x;
	double y;
	double z;
} vector;

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
vector add(vector a, vector b);

/**
* @brief takes the input of vector values and subs them accordingly
* @param[in] parameter_name (Define its Parameters)
* @remark inputted values may be a floating point number and should be handled accordingly
*/
vector sub(vector a, vector b);

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
vector scale(vector a, double s);

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark Extra Credit Case
*/
double dot(vector a, vector b);

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark Extra Credit Case
*/
vector cross(vector a, vector b);

#endif