/*************************
* @file vector.h
* @brief a definer file for vector with Defined constants
* @author Harley Soto
* @date 10/15/26
*
* @version 1.0
*************************/
#ifndef VECTOR_H
#define VECTOR_H

/**
* @brief this is a set character length for the name of each vector up to 32 Character
*/
#define NAME_LENGTH 32


/**
* @brief creates a array of Vectors with Name , Value x, Value y, and Value z. Up to 3 values
*/

typedef struct{
	char name[NAME_LENGTH];
	double x;
	double y;
	double z;
} vector;

/**
* @brief takes the input of vector values and adds them accordingly
* @param[in] a this is the first defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @param[in] b this is the second defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @remark This function can take a integers/floats/or Vectors if previously defined
* @return r - Vector Value / Calculation
*/
vector add(vector a, vector b);

/**
* @brief takes the input of vector values and subs them accordingly
* @param[in] a this is the first defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @param[in] b this is the second defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @remark This function can take a integers/floats/or Vectors if previously defined
* @return r - Vector Value / Calculation
*/
vector sub(vector a, vector b);

/**
* @brief takes the input of vector values and subs them accordingly
* @param[in] a this is the first defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @param[in] b this is the second defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @remark This function can take a integers/floats/or Vectors if previously defined
* @return r - Vector Value / Calculation
*/
vector scale(vector a, double s);

/**
* @brief takes the input of vector values and subs them accordingly
* @param[in] a this is the first defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @param[in] b this is the second defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @remark This function can take a integers/floats/or Vectors if previously defined
* @return r - Vector Value / Calculation
*/
double dot(vector a, vector b);

/**
* @brief takes the input of vector values and subs them accordingly
* @param[in] a this is the first defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @param[in] b this is the second defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @remark This function can take a integers/floats/or Vectors if previously defined
* @return r - Vector Value / Calculation
*/
vector cross(vector a, vector b);

#endif