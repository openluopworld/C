
## C Traps and Pit Falls

### Chapter 2
* 函数指针(*p)()也可以简写为p();
* 运算符优先级：优先级比单目运算符要低的，接下来就是双目运算符。在双目运算符中，算上运算符的优先级最高，移位运算符次之，关系运算符再次之，接着是逻辑运算符，条件运算符（三目运算符），赋值运算符，逗号运算符；（原书说条件运算符在赋值运算符后面是错的，page 31）
* 结构体、联合等也是一种数据类型，在定义的后面需要加分号，这样可以防止在函数没有明确指定返回值的条件下直接将结构体或者联
合作为一种返回类型；（page 34）
* The malloc and free function should be used at the same scope.
* 一维数组作为形参时会自动地被转化为指针类型；多维数组作为函数参数时，只是将最里面的一层转化为指针，就像洋葱最里面的一层;将数组作为函数的形参，而不是直接使用指针作为形参的一个好处是便于阅读，例如AES一个block的加密;
```C
#define BLOCK_SIZE_IN_BYTES 16
#define ROUND_KEY_SIZE_IN_BYTES 176

/**
 * Encrypt one block with aes
 */
void aes_encrypt (unsigned char *roundkeys, unsigned char *plain, unsigned char *cipher) ;
void aes_encrypt (unsigned char roundkeys[176], unsigned char plain[16], unsigned char cipher[16]) ;
```
* String in C is a const value. Its contents can not be modified.
```C
char *q = "xyz";
// q[1] = "A"; // Compile no error with gcc-4.8.4, but error at run time.
strlen(q); // 3
sizeof("xyz"); // 4
```
```C
size_t strlen (char const *string) {
	int length;
	for (lenght = 0; *string++ != '\0'; ) {
		length += 1;
	}
	return length;
}
```
