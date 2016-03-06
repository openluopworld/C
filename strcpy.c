
#include <stdio.h>

void strcpy ( char *s, char *t) {
	while ( (*s = *t) != '\0' ) {
		s++;
		t++;
	}
}

/**
 * the ++ operation can be put together with *
 */
void strcpy ( char *s, char *t) {
	while ( (*s++ = *t++) != '\0')
		;
}

/**
 * since the value of '\0' is just 0, it can be more simple.
 */
void strcpy ( char *s, char *t) {
	while ( *s++ = *t++ )
		;
}

int main () {
	
}

