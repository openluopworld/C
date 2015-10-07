
#include<stdio.h>

/*
 * Output the content of the input(file or stdio)
 */
int main () {
	int i;
	/*
	 * On linux
	 * At the start of a new line: Ctrl+D to end input.
	 * If not at the start: first "Ctrl+D" to output the input, second "Ctrl+D" to end intpu.
	 */
	while ( (i = getchar() ) != EOF) {
		putchar(i);
	}
}
