#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if UNIT_TESTING
#ifdef printf
#undef printf
#endif 
#define printf example_test_printf
extern void print_message(const char *format, ...);
#ifdef fprintf
#undef fprintf
#endif 
#define fprintf example_test_fprintf
extern int example_test_fprintf(FILE * const file, const char *format, ...);
#ifdef assert
#undef assert
#endif 
#define assert(expression) \
	mock_assert((int)(expression), #expression, __FILE__, __LINE__)
void mock_assert(const int result, const char* expression, const char *file, 
                 const int line);
#ifdef calloc
#undef calloc
#endif 
#define calloc(num, size) _test_calloc(num, size, __FILE__, __LINE__)
#ifdef free
#undef free
#endif 
#define free(ptr) _test_free(ptr, __FILE__, __LINE__)
void* _test_calloc(const size_t number_of_elements, const size_t size, 
                   const char* file, const int line);
void _test_free(void* const ptr, const char* file, const int line);
#define main example_main
#define static
#endif 
typedef int (*BinaryOperator)(int a, int b);
typedef struct OperatorFunction {
	const char* operator;
	BinaryOperator function;
} OperatorFunction;
static int add(int a, int b);
static int subtract(int a, int b);
static int multiply(int a, int b);
static int divide(int a, int b);
static OperatorFunction operator_function_map[] = {
	{"+", add},
	{"-", subtract},
	{"*", multiply},
	{"/", divide},
};
static int add(int a, int b) {
	return a + b;
}
static int subtract(int a, int b) {
	return a - b;
}
static int multiply(int a, int b) {
	return a * b;
}
static int divide(int a, int b) {
	assert(b);  
	return a / b;
}
static BinaryOperator find_operator_function_by_string(
        const size_t number_of_operator_functions,
        const OperatorFunction * const operator_functions,
        const char* const operator_string) {
	size_t i;
	assert(!number_of_operator_functions || operator_functions);
	assert(operator_string);
	for (i = 0; i < number_of_operator_functions; i++) {
		const OperatorFunction *const operator_function =
		    &operator_functions[i];
		if (strcmp(operator_function->operator, operator_string) == 0) {
			return operator_function->function;
		}
	}
	return NULL;
}
static int perform_operation(
        int number_of_arguments, char *arguments[],
        const size_t number_of_operator_functions, 
        const OperatorFunction * const operator_functions,
        int * const number_of_intermediate_values,
        int ** const intermediate_values, int * const error_occurred) {
	char *end_of_integer;
	int value;
	unsigned int i;
	assert(!number_of_arguments || arguments);
	assert(!number_of_operator_functions || operator_functions);
	assert(error_occurred);
	assert(number_of_intermediate_values);
	assert(intermediate_values);
	*error_occurred = 0;
	*number_of_intermediate_values = 0;
	*intermediate_values = NULL;
	if (!number_of_arguments)
		return 0;
	value = (int)strtol(arguments[0], &end_of_integer, 10);
	if (end_of_integer == arguments[0]) {
		fprintf(stderr, "Unable to parse integer from argument %s\n", 
		        arguments[0]);
		*error_occurred = 1;
		return 0;
	}
	*intermediate_values = calloc(((number_of_arguments - 1) / 2),
	                              sizeof(**intermediate_values));
	i = 1;
	while (i < number_of_arguments) {
		int other_value;
		const char* const operator_string = arguments[i];
		const BinaryOperator function = find_operator_function_by_string(
		    number_of_operator_functions, operator_functions, operator_string);
		int * const intermediate_value = 
		    &((*intermediate_values)[*number_of_intermediate_values]);
		(*number_of_intermediate_values) ++;
		if (!function) {
			fprintf(stderr, "Unknown operator %s, argument %d\n",
			        operator_string, i);
			*error_occurred = 1;
			break;
		}
		i ++;
		if (i == number_of_arguments) {
			fprintf(stderr, "Binary operator %s missing argument\n",
			        operator_string);
			*error_occurred = 1;
			break;
		}
		other_value = (int)strtol(arguments[i], &end_of_integer, 10);
		if (end_of_integer == arguments[i]) {
			fprintf(stderr, "Unable to parse integer %s of argument %d\n",
			        arguments[i], i);
			*error_occurred = 1;
			break;
		}
		i ++;
		*intermediate_value = function(value, other_value);
		value = *intermediate_value;
	}
	if (*error_occurred) {
		free(*intermediate_values);
		*intermediate_values = NULL;
		*number_of_intermediate_values = 0;
		return 0;
	}
	return value;
}
int main(int argc, char *argv[]) {
	int return_value;
	int number_of_intermediate_values;
	int *intermediate_values;
	const int result = perform_operation(
	    argc - 1, &argv[1], 
	    sizeof(operator_function_map) / sizeof(operator_function_map[0]),
	    operator_function_map, &number_of_intermediate_values, 
	    &intermediate_values, &return_value);
	if (!return_value && argc > 1) {
		unsigned int i;
		unsigned int intermediate_value_index = 0;
		printf("%s\n", argv[1]);
		for (i = 2; i < argc; i += 2) {
			assert(intermediate_value_index < number_of_intermediate_values);
			printf("  %s %s = %d\n", argv[i], argv[i + 1],
			       intermediate_values[intermediate_value_index++]);
		}
		printf("= %d\n", result);
	}
	if (intermediate_values) {
		free(intermediate_values);
	}
	return return_value;
}