/*************************
* @file vector.c 
* @brief Calculated vectors dependent on selected method add,sub,scale,dot,cross. (Equations)
* @author Harley Soto
* @date 10/15/26
*
* @version 1.0
*************************/
#include "vector.h"

/**
* @brief takes the input of vector value and adds them accordingly
* @param[in] a this is the first defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @param[in] b this is the second defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @remark This function can take a constant,float or vector if previously defined
* @return r - Vector Value / Calculation
*/
vector add(vector a, vector b){
	vector r = {"", a.x + b.x, a.y + b.y, a.z + b.z};
	return r;
}

/**
* @brief takes the input of vector values and subs them accordingly
* @param[in] a this is the first defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @param[in] b this is the second defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @remark This function can take a integers/floats/or Vectors if previously defined
* @return r - Vector Value / Calculation
*/
vector sub(vector a, vector b){
	vector r = {"", a.x - b.x, a.y - b.y, a.z - b.z};
	return r;
}

/**
* @brief takes the input of vector value and scales them accordingly
* @param[in] a this is the first defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @param[in] s this is the second defined case value that MUST be a constant to scale the first Value/Vector
* @remark This function can take a constant,float or vector if previously defined
* @return r - Vector Value / Calculation
*/
vector scale(vector a, double s){
	vector r = {"", a.x * s, a.y * s, a.z * s};
	return r;
}

/**
* @brief takes the input of vector value and multiplies them accordingly
* @param[in] a this is the first defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @param[in] b this is the second defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @remark This function can take a constant,float or vector if previously defined
* @return r - Vector Value / Calculation
*/
double dot(vector a, vector b){
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

/**
* @brief takes the input of vector value and multiplies them using a third values using matrix
* @param[in] a this is the first defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @param[in] b this is the second defined case value take a constant (1,2,3...) or a vector (a,b,c...)
* @remark This function can take a constant,float or vector if previously defined
* @return r - Vector Value / Calculation
*/
vector cross(vector a, vector b){
	vector r;
	r.name[0] = '\0';
	r.x = a.y * b.z - a.z * b.y;
	r.y = a.z * b.x - a.x * b.z;
	r.z = a.x * b.y - a.y * b.x;
	return r; 
}