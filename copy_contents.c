
#include<stdio.h>

/**
 * Output the content of the input(file or stdio)
 *
 * @code
 * extern int getchar(void);
 * @endcode
 * @par Purpose
 * read a character from stdin.
 *
 * @code
 * extern int putchar(int __c);
 * @endcode
 * @par Purpose
 * write a character to stdout.
 *
 * @code
 * #ifnde EOF
 * #define EOR (-1)
 * #endif
 * @par Purpose
 * end of file character.
 *
 * @code
 * extern int fgetc (FILE *__stream);
 * @endcode
 * @par Purpose
 * read a character from stream
 *
 * @code
 * extern int fputc (int __c, FILE *__stream);
 * @endcode
 * @par Purpose
 * write a character to stream
 *
 * @code
 * extern int fclose (FILE *__stream);
 * @endcode
 * @par Purpose
 * close stream
 */

#define FILE_INPUT ("/home/luopeng/Desktop/input.txt")
#define FILE_OUTPUT ("/home/luopeng/Desktop/output.txt")

/**
 * @par purpose
 * copy file
 */
void copy_file () {

	FILE * finput = fopen(FILE_INPUT, "r");
	FILE * foutput = fopen(FILE_OUTPUT, "w");

	if ( NULL == finput) {
		printf("Fail to open file %s.\n", FILE_INPUT);
	} else if ( NULL == foutput ) {
		printf("Fail to open file %s.\n", FILE_OUTPUT);
	} else {
		int ch;
		while ( (ch = fgetc(finput)) != EOF ) {
			fputc(ch, foutput);
		}
	}

	if ( NULL != finput ) { fclose(finput); }
	if ( NULL != foutput ) { fclose(foutput); }

	return ;
}

/**
 * @code
 * void print_eof ();
 * @endcode
 * @par purpose
 * printf the value of EOF
 */
void print_eof () {
	int c;
	/*
	 * On linux
	 * The method to end input from stdin
	 * At the start of a new line: Ctrl+D to end input.
	 * If not at the start: first "Ctrl+D" to output the input, second "Ctrl+D" to end intpu.
	 */
	while ( (c = getchar()) != EOF ) 
	printf("%d\n", c);
}

/**
 * @code
 * int count_lines(); 
 * @endcode
 *
 * @par purpose
 * count the line of a file
 */
int count_lines () {
	
}


int main () {
	print_eof();
}
