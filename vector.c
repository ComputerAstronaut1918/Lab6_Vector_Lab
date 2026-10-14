/*************************
* @file Vector.c 
* @breif 
* @author Harley Soto
* @date
*
* @version 1.0
*************************/
#include "vector.h"

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
vector add(vector a, vector b){
	vector r = {"", a.x + b.x, a.y + b.y, a.z + b.z};
	return r;
}

/**
* @brief takes the input of vector values and subs them accordingly
* @param[in] parameter_name (Define its Parameters)
* @remark inputted values may be a floating point number and should be handled accordingly
*/
vector sub(vector a, vector b){
	vector r = {"", a.x - b.x, a.y - b.y, a.z - b.z};
	return r;
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
vector scale(vector a, double s){
	vector r = {"", a.x * s, a.y * s, a.z * s};
	return r;
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
double dot(vector a, vector b){
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
vector cross(vector a, vector b){
	vector r;
	r.name[0] = '\0';
	r.x = a.y * b.z - a.z * b.y;
	r.y = a.z * b.x - a.x * b.z;
	r.z = a.x * b.y - a.y * b.x;
	return r; 
}