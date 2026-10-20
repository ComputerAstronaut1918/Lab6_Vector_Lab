/*************************
* @file interface.c
* @brief  
* @author Harley Soto
* @date 10/15/26
*
* @version 1.0
*************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include "interface.h"
#include "vector.h"
#include "array.h"

#define LINE_LENGTH 256
#define MAX_TOKENS 16

#define OPERAND_VECTOR 1
#define OPERAND_NUMBER 2

/**
* @brief (Define Function)
* @param[in] *name this is the 32 char limit character name assigned
* @param[in] v this is the returned vector from the typedef structure array
* @remark (Ad extraneous cases)
*/
static void print_vector(const char *name, vector v){
	printf("%s = %g %g %g\n", name, v.x, v.y, v.z);
}

/**
* @brief prints a simple usage message to console to assist in proper input and other commands.
*/
void print_help(void){
	printf("\nVectorCalc - a minimal vector calculator (w/ 3 component vectors)\n"
		"\n"
		"VectorCalc [-h]\n"
		"\n"
		"Commands - *Spaces are required around '=' and operators*:\n"
		" a = 1 2 3			Create/replace vector(s)						\n"
		" a 				Creates a empty vector							\n"
		" a + b				Adds the vector(s) values 						\n"
		" a - b				Sub the vector(s) values 						\n"
		" a * 2.5			Multiplies a vector by the defined constant  	\n"
		" a . b				Create/replace vector(s)						\n"
		" a x b 			Create/replace vector(s)						\n"
		" c = a + b			Create/replace vector(s)						\n"
		" list				- List(s) All stored vectors					\n"
		" clear				- Clear(s) All stored vectors					\n"
		" help				- Shows a Help Menu								\n"
		" quit				- Exit the program								\n"
		"\n"
		"up to %d vectors may be stored at once.\n", MAX_VECTORS
	);
}

/**
* @brief this is a number check to determine if a number was used and if its valid/ check for not vector
* @param[in] *s (Define its Parameters)
* @param[in] *out (Define its Parameters)
* @remark (Ad extraneous cases)
*/
static int is_number(const char *s, double *out){
	char *end;
	
	if(!(isdigit((unsigned char)s[0]) || ((s[0] == '-' || s[0] == '+' || s[0] == '.') && s[1] != '\0'))){
		return 0;
	}
	
	/**
	* @brief strtod take the incoming char s and turns it into a floating point value provided by stdlib.h strtod(constant char *ptr, char *ptr2)
	*/
	*out = strtod(s, &end);
	return end != s && *end == '\0';
}

/**
* @brief this defines if the inputted character is a predefined character if not will return a error or check
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
static int is_reserved(const char *s){
	return strcmp(s, "quit") == 0 || strcmp (s, "clear") == 0 || strcmp(s, "list") == 0 || strcmp(s,"help") == 0 || strcmp(s,"exit") == 0; 
}

/**
* @brief this determines if the name given is valid for use / prevents duplicates and 32 char limit
* @param[in] *s (Define its Parameters)
* @remark (Ad extraneous cases)
*/
static int is_valid_name(const char *s){
	size_t i;
	
	if(!isalpha((unsigned char)s[0]) || strlen(s) >= NAME_LENGTH || is_reserved(s)){
		return 0;
	}
	for(i = 1; s[i] != '\0'; i++){
		if(!isalnum((unsigned char)s[i]) && s[i] != '_'){
			return 0;
		}
	}
	return 1;
}

/**
* @brief this determines if the value given was a number or a vector to calculate
* @param[direction] parameter_name (Define its Parameters)
*/
static int is_operator(const char *s){
	return strlen(s) == 1 && strchr("+-*.x",s[0]) != NULL;
}

/**
* @brief this gets the operand for calculation... 
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
static int get_operand(const char *token, vector *v, double *d){
	if(is_number(token, d)){
		return OPERAND_NUMBER;
	}
	if(findvector(token, v) == 0){
		return OPERAND_VECTOR;
	}
	printf("Error: '%s' is not a number or and existing vector\a\n", token);
	return 0;
}

/**
* @brief this evaluates the given values for the calculation and determines if it follows the rules
* @param[direction] parameter_name (Define its Parameters)
* @remark (Ad extraneous cases)
*/
static int evaluate(const char *l, const char *op, const char *r, vector *vres, double *sres, int *is_scalar){
	vector lv,rv;
	double ld,rd;
	int    lt,rt;
	
	lt = get_operand(l, &lv, &ld);
	if(lt == 0){
		return -1;
	}
	rt = get_operand(r, &rv, &rd);
	if(rt == 0){
		return -1;
	}
	
	*is_scalar = 0;
	switch (op[0]){
		case '+':
		case '-':
			if(lt != OPERAND_VECTOR || rt != OPERAND_VECTOR){
				printf("Error: '%s' requires two vectors \a\n", op);
				return -1;
			}
			*vres = (op[0] == '+') ? add (lv, rv): sub(lv, rv);
			return 0;
		case '*':
			if(lt == OPERAND_VECTOR && rt == OPERAND_NUMBER){
				*vres = scale(lv, rd);
			}else if (lt == OPERAND_NUMBER && rt == OPERAND_VECTOR){
				*vres = scale(rv,ld);
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
* @brief this list the vectors for printing / counts
*/
static void do_list(void){
	int i,n = countvectors();
	vector v;
	
	if(n == 0){
		printf("No vectors stored\a\n");
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
* @brief this assigns the values for the struct array
* @param[direction] parameter_name (Define its Parameters)
*/
static void assignment(char *token[], int n){
	const char *name = token[0];
	int m = n - 2;
	char **rhs = token + 2;
	vector v;
	double val[3] = {0.0, 0.0,0.0};
	double s;
	int is_scalar, i;
	
	
	if(!is_valid_name(name)){
		printf("Error: invalid vector name '%s'\a\n", name);
		return;
	}
	
	if(m == 3 && is_operator(rhs[1])){
		if(evaluate(rhs[0], rhs[1], rhs[2], &v, &s, &is_scalar) != 0){
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
	for(i = 0; i < m; i++){
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
* @brief this function handles input and check for numbers/ vectors / and commands
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
	for(p = strtok(line, " \t\r\n"); p != NULL; p = strtok(NULL, " \t\r\n")){
		if(n == MAX_TOKENS){
			printf("Error: too many items on the line\a\n");
			return 0;
		}
		token[n++] = p;
	}	
	if(n == 0){
		return 0;
	}
	
	if( n == 1){
		if(strcmp(token[0], "quit") == 0){
			return 1;
		} else if(strcmp(token[0], "exit") == 0){
			return 1;
		} else if(strcmp(token[0], "list") == 0){
			do_list();
		} else if(strcmp(token[0], "clear") == 0){
			clearvectors();
			printf("All vectors cleared\a\n");
		} else if(strcmp(token[0], "help") == 0){
			print_help();
		} else if(findvector(token[0], &v) == 0){
			print_vector(v.name, v);
		} else {
			printf("Error: vector '%s' does not exist\a\n", token[0]);
		}
	} else if(n == 3 && is_operator(token[1])){
		if(evaluate(token[0], token[1], token[2], &v, &s, &is_scalar) == 0){
			if(is_scalar){
				printf("ans = %g\n", s);
			} else {
				print_vector("ans",v);
			}
		}
	} else if (n >= 3 && strcmp(token[1], "=") == 0){
		assignment(token, n);
	} else {
		printf("Error: invalid command (type 'help' for usage)\n");
	}
	return 0;
}

/**
* @brief this is the (main) run function for the program after its starts in VectorCalc
*/
void runCalc(void){
	char line[LINE_LENGTH];
	
	for(;;){
		printf("VectorCalc> ");
		fflush(stdout);
		if(fgets(line, sizeof(line), stdin) == NULL){
			printf("\n");
			break;
		}
		if(strchr(line, '\n') == NULL && strlen(line) == LINE_LENGTH -1){
			int c;
			while((c = getchar()) != '\n' && c != EOF){
				;
			}
			printf("Error: line too long\a\n");
			continue;
		}
		if(input_handler(line)){
			break;
		}
	}
}