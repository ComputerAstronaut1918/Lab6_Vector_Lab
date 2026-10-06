/*************************
* @file 
* @breif 
* @author Harley Soto
* @date
*
* @version 1.0
*************************/

typedef struct{
	char name[NAME_LENGTH]
	char x;
	char y;
	char z;
}Vector

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
Vector Add(vect a, vect b)

/**
* @brief takes the input of vector values and subs them accordingly
* @param[in] parameter_name (Define its Parameters)
* @remark inputted values may be a floating point number and should be handled accordingly
*/
Vector Sub(vect a, vect b)

/**
* @brief takes the input of vector values and multi them accordingly
* @param[in] parameter_name (Define its Parameters)
* @remark inputted values may be a floating point number and should be handled accordingly
*/
Vector Mult(vect a, vect b)

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
Vector double scale(vect a, vect b)

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
Vector double dot(vect a, vect b)

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
Vector  cross(vect a, vect b)

#endif