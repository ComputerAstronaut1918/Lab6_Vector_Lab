/*************************
* @file Vector.c 
* @breif 
* @author Harley Soto
* @date
*
* @version 1.0
*************************/
#include "Vector.h"

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
Vector add(vect a, vect b){
	vect r = {"", a.x + b.x + a.y + b.y + a.z + b.z};
	return r;
}

/**
* @brief takes the input of vector values and subs them accordingly
* @param[in] parameter_name (Define its Parameters)
* @remark inputted values may be a floating point number and should be handled accordingly
*/
Vector sub(vect a, vect b){
	vect r = {"", a.x - b.x - a.y - b.y - a.z - b.z};
	return r;
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
Vector scale(vect a, double s){
	vect r = {"", a.x * s, a.y * s, a.x * s};
	return r;
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
double dot(vect a, vect b){
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
Vector cross(vect a, vect b){
	vect r;
	r.name[0] = '\0';
	r.x = a.y * b.z - a.z * b.y;
	r.y = a.z * b.x - a.x * b.z;
	r.z = a.x * b.y - a.y * b.x;
	return r; 
}