
### extern

如果一个全局变量多个源文件需要共享，可以按照如下方式组织文件。<br>
```C
// common.h:变量申明文件
extern double PI;
```

```C
// common.c:变量定义文件
#include "common.h"

double PI = 3.14;
```

```C
//　其它用到变量的文件
#include "common.h"

double perimeter (double r) {
	return 2*r*PI;
}

double square (double r) {
	return r*r*PI;
}
```

另一种方式是直接在头文件中申明并定义，需要使用到的源文件通过extern导入。
```C
// common.c:变量定义文件
double PI = 3.14;
```

```C
//　其它用到变量的文件
extern double PI;

double perimeter (double r) {
	return 2*r*PI;
}

double square (double r) {
	return r*r*PI;
}
```
