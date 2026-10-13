/*************************
* @file 
* @breif 
* @author Harley Soto
* @date
*
* @version 1.0
*************************/
#ifndef VECTOR.H
#define VECTOR.H
#define NAME_LENGTH 32

typedef struct{
	char name[NAME_LENGTH]
	double x;
	double y;
	double z;
}vector;

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
vector add(vect a, vect b)

/**
* @brief takes the input of vector values and subs them accordingly
* @param[in] parameter_name (Define its Parameters)
* @remark inputted values may be a floating point number and should be handled accordingly
*/
vector sub(vect a, vect b)

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
vector scale(vect a, double s)

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark Extra Credit Case
*/
double dot(vect a, vect b)

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark Extra Credit Case
*/
vector cross(vect a, vect b)

#endif