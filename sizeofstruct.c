
#include <stdio.h>


typedef struct Test {
	int Num;
	char *pcName;
	short sDate;
	char cha[2];
	short sBa[4];
} Test;

int main ( void ) {

	Test test;
	test.Num = 0x01020304;
	test.pcName = (char*)(0x05060708090aL);
	test.sDate = 0x0d0e;
	test.cha[0] = 0x0f;
	test.cha[1] = 0x10;
	test.sBa[0] = 0x1011;
	test.sBa[1] = 0x1213;
	test.sBa[2] = 0x1415;
	test.sBa[3] = 0x1617;
	printf("%d\n", (unsigned int)sizeof(test));

	char * temp = (char*)&test;
	int i;
	for ( i = 0; i < sizeof(test); i++ ) {
		printf("%x\n", temp[i]);
	}

	return 0;

}
