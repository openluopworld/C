
/**
 * the use of 'static'
 */

#include <stdio.h>

#define TEST_STATIC (3)

/**
 * in a function.
 * the variable is only once
 */
int in_a_fun () {
	static count = 0;
	count++;
	printf("count = %d\n", count);
}

/**
 * the static variable out of a function is only visible to the functions in this file
 */
static int out_fun = 0;

void add() {
	out_fun++;
}

void sub() {
	out_fun--;
}

void print_value () {
	printf("out_fun = %d\n", out_fun);
}
/* static out of a function end */


/**
 * static to modify a function, the function is only visible to this file
 */
static int get_next () {
	printf("static function can only be seen in the file where it was defined.\n");
}

int main () {

#if defined(TEST_STATIC) && (TEST_STATIC==1)
	in_a_fun();
	in_a_fun();
#elif defined(TEST_STATIC) && (TEST_STATIC==2)
	print_value();
	add();
	print_value();
	sub();
	sub();
	print_value();
#elif defined(TEST_STATIC) && (TEST_STATIC==3)
	get_next();
#endif
	return 0;
}
