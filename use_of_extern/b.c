
#include <stdint.h>
#include <stdio.h>

#include "a.h"

uint8_t sub (uint8_t x) {
	return x-a;
}

int main () {
	printf("%d\n", sub(8));
	return 0;
}
