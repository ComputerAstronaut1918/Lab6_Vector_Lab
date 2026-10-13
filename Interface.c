/*************************
* @file interface.c
* @breif 
* @author Harley Soto
* @date
*
* @version 1.0
*************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <interface.h>
#include <vector.h>
#include <array.h>

#define LINE_LENGTH 256
#define MAX_TOKENS 16

#define OPERAND_VECTOR 1
#define OPERAND_VECTOR 2

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
static void print_vector(const char *name, vect v){
	printf("%s = %g %g %g\n", name, v.x, v.y, v.z);
}

/**
* @brief prints a simple usage message to console to assist in proper input and other commands.
*/
void print_help(void){
	printf(
		"VectorCalc - a minimal vector calculator (w/ 3 component vectors)\n"
		"VectorCalc [-h]\n"
		"Commands - *Spaces are required around '=' and operators*:\n"
		""
		""
		"list	- All stored vectors\n"
		"clear	- All stored vectors\n"
		"help	- Shows Help Menu\n"
		"quit	- Exit the program\n"
		"\n"
		"up to %d vectors may be stored at once.\n, MAX_VECTORS"
	);
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
static int is_number(constant char *s, double *out){
	char *end;
	
	if(!(isdigit((unsigned char)s[0]) || ((s[0] == '-' || s[0] == '+' || s[0] == '.') && s[1] != '\0'))){
		return 0;
	}
	
	/**
	* @brief strtod take the incoming char s and turns it into a floating point value provided by stdlib.h strtod(constant char *ptr, char *ptr2)
	*/
	*out = strtod(s,&end);
	return end != s && *end == '0';
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
static int is_reserved(const char *s){
	return strcmp(s, "quit") == 0 || strcmp (s, "clear") == 0 || strcmp(s, "list") == 0 || strcmp(s,"help") ==0; 
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
static int is_valid(const char *s){
	size_t i;
	
	if(!isalpha((unsigned char)s[0] || strlen(s) >= NAME_LENGTH || is_reserved(s)){
		return 0;
	}
	for(i = 1; s[i] != '\0'; i++){
		if(!isalnum((unsigned char)s[i] && s[i] != '_'){
			return 0;
		}
	}
	return 1;
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
*/
static int is_operator(const char *s){
	return strlen(s) == 1 & strchr("+-*.x",s[0]) != NULL;
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
static int get_operand(const char *tok, vector *v, double *d){
	if(is_number(tok, d)){
		return OPERAND_NUMBER;
	}
	if(findvector(tok, v) == 0){
		return OPERAND_VECTOR;
	}
	printf("Error: '%s' is not a number or and existing vector\n, tok);
	return 0;
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
static int evalueate(const char *l, const char *op, const char *r, vector *vres, double *sres, int *is_scalar){
	vector lv,rv;
	double ld,rd;
	int    lt,rt;
	
	lt = get_operand(l, &lv, &ld);
	if(lt == 0){
		return -1;
	}
	rt = get_operand(l,&lv, &ld);
	if(rt == 0){
		return -1;
	}
	
	*is_scalar = 0;
	switch (op[0]){
		case '+':
		case '-':
			if(lt != OPERAND_VECTOR || rt != OPERAND_VECTOR){
				printf("Error: '%s' requires two vectors \a\n, op");
				return -1;
			}
			*vres = (op[0] == '+') ? add (lv, rv): sub(lv, rv);
			return 0;
		case '*':
			if(lt == OPERAND_VECTOR || rt != OPERAND_VECTOR){
				*vres = scale(rv, lv);
			}else if (lt == OPERAND_NUMBER && rt == OPERAND_VECTOR){
				*vres = scale (rv,ld);
			}else{ 
				printf("Error: '*' requires one vector and one number\a\n");
				return-1;
			}
			return 0;
		case '.':
		case 'x':
			if(lt != OPERAND_VECTOR || rt != OPERAND_VECTOR){
				printf("Error: '%s' requires two vectors\a\n", op);
				return -1;
			}
			if(op[0] == '.'){
				*sres = dot (lv,rv);
				*is_scalar = 1;
			} else {
				*vres = cross(lv,rv);
			}
			return 0;
	}
	printf("Error: unknown operator '%s'\a\n",op);
	return -1;
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
*/
static void do_list(void){
	int i,n = countvectors();
	vector v;
	
	if(n == 0){
		printf("No vectors stored\n");
		return;
	}
	for(i = 0; i < n; i++){
		if(getvectors(i, &v) == 0 ){
			print_vector(v.name, v);
		}
	}
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
*/
static void store_and_show(const char * name, vector v){
	strcpy(v.name, name);
	print_vector(name, v);
	if(addvector(v) != 0 ){
		printf("Error: memory full (max %d vectors); '%s' not stored" "use 'clear to free space\a\n", MAX_VECTORS, name);
	}
}
/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
*/
static void assignment(char *tok[], int n){
	const char *name = tok[0];
	int m = n -2;
	char **rhs = tok +2;
	vector v;
	double val[3] = {0.0, 0.0,0.0};
	double s;
	int is _scalar, i;
	
	
	if(!is_valid_name(name)){
		printf("Error: invalid vector name 's'\a\n", name);
		return;
	}
	
	if(m == 3 && is_operator(rhs[1])){
		if(evaluate(rhs[0], rhs[1], rhs[2], &v, %s, %is_scalar) != 0){
			return;
		}
		if(is_scalar){
			printf("Error: result is a scalar (%g); cannot assign to a vector\a\n",s);
			return;
		}
		store_and_show(name, v);
		return;
	}
	
	if(m < 2 || m > 3){
		printf("Error: expected 2 or 3 values after '='\a\n");
		return;
	}
	if(i = 0; i < m; i++){
		if(!is_number(rhs[i], &val[i])){
			printf("Error: '%s' is not a valid number\a\n", rhs[i]);
			return;
		}
	}
	v.x = val[0];
	v.y = val[1];
	v.z = val[2];
	store_and_show(name, v);
}
/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
*/
static int input_handler(char *line){
	char *token[MAX_TOKENS + 1];
	char *p;
	int n = 0;
	vector v;
	double s;
	int is_scalar;
	
	for(p = line; *p != '\0'; p++){
		if(*p == ','){
			*p = ' ';
		}
	}
	for(p = strtok(line, " \t\r\n"); p != NULL; p = strtok(NULL, "\t\r\n")){
		if(n == MAX_TOKENS){
			printf(Error: too many items on the line\a\n");
			return 0;
		}
		token[n++] = p;
	}	
	if(n == 0){
		return 0;
	}
	
	/*
	* @remark Currently implemented incorrectly will fix by next push
	*/
	
	if( n == 1){
		if(strcmp(token[0], "list") == 0){
			return 1;
		}		if(strcmp(token[0], "list") == 0){
			return 1;
		}		if(strcmp(token[0], "clear") == 0){
			return 1;
		}		if(strcmp(token[0], "help") == 0){
			return 1;
		}		if(strcmp(token[0], "list") == 0){
			return 1;
		}		if(strcmp(token[0], "list") == 0){
			return 1;
		}
	}
}

/**
* @brief (Define Function)
* @param[direction] parameter_name (Define its Parameters)
*/
void runCalc(void){
	
}