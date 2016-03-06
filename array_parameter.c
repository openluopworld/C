
#include <stdio.h>

#define LINE (3)
#define COL (4)

/**
 * compute the sum of an array
 * the following three methods are all correct
 * 
 * understand the difference between 
 *	int *a[10] and
 *	int (*a)[10]
 * the priority of [] is higher than *
 */
int sum ( int array[LINE][COL]) {
	
}

int sum ( int array[][COL] ) {
	
}

int sum ( int (*array)[COL] ) {
	
}

int main () {
	
}
