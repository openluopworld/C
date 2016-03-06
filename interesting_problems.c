
/*
 * Some interesting problems in c
 *
 * From: http://github.tiankonguse.com/blog/2014/12/05/c-base.html
 */

#include <stdio.h>

#define TOTAL_ELEMENTS (sizeof(array) / sizeof(array[0]))

void from_0_index () {
	int array[] = {23, 34, 12, 17, 204, 99, 16};
	int i;
	for(i = -1; i <= (TOTAL_ELEMENTS-2); i++) {
		printf("%d\n",array[i+1]);
	}
	printf("%s\n", "end");
}


int array (int a[][10]) {
	
}

// for test
int main () {
	int a[10][10];
	array(a);
	return 0;
}
