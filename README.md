# C

<b>Chapter1</b><br>
1) printf打印<br>
&nbsp;&nbsp;&nbsp;&nbsp;%d,按照十进制整数打印<br>
&nbsp;&nbsp;&nbsp;&nbsp;%ld,long int<br>
&nbsp;&nbsp;&nbsp;&nbsp;%6d,按照十进制整数打印，<b>至少</b>6个字符宽<br>
&nbsp;&nbsp;&nbsp;&nbsp;%f,按照浮点数打印<br>
&nbsp;&nbsp;&nbsp;&nbsp;%6f,按照浮点数打印，至少6个字符宽<br>
&nbsp;&nbsp;&nbsp;&nbsp;%.2f,按照浮点数打印，小数点后有两位小数<br>
&nbsp;&nbsp;&nbsp;&nbsp;%6.2f,按照浮点数打印，至少6个字符宽，小数点后有两位小数<br>
&nbsp;&nbsp;&nbsp;&nbsp;%o,八进制数<br>
&nbsp;&nbsp;&nbsp;&nbsp;%x,十六进制数<br>
&nbsp;&nbsp;&nbsp;&nbsp;%c,字符<br>
&nbsp;&nbsp;&nbsp;&nbsp;%s,字符串<br>
&nbsp;&nbsp;&nbsp;&nbsp;%%,百分号本身<br>
2) EOF<br>
&nbsp;&nbsp;&nbsp;&nbsp;value of EOF is -1<br>
&nbsp;&nbsp;&nbsp;&nbsp;EOF is NOT:<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;a) A char<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;b) A value that exists at the end of a file<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;c) A value that could exist in the middle of a file<br>
&nbsp;&nbsp;&nbsp;&nbsp;<b>EOF is a macro defined as an int with a negative value. It is normally returned by functions that perform read operations to denote either an error or end of input.</b><br>

<b>Chapter1</b><br>
1) int, short, long<br>
&nbsp;&nbsp;&nbsp;&nbsp;short与long两个限定符的引入可以为我们提供满足实际需要的不同长度的整型数。int通常代表特定机器中整数的自然长度。short类型通常为16位,long类型通常为32位，int类型可以是16位或32位。各编译器可以根据硬件特征自主选择合适的类型长度，但要遵循下列限制：short与int类型至少为16位，而long类型至少为32位，并且short类型不得长于int类型，而int类型不得长于long类型。<br>
2) 字符常量与仅包含一个字符的字符串之间的区别：'x'与"x"是不同的，前者是一个整数，其值是字母x在机器字符集中对应的数值（内部表示值）；后者是一个包含一个字符x以及一个结束符'\0'的字符数组。<br>
3) 库函数sqrt的参数为double类型，如果处理不当，结果可能会无意义（sqrt在<math.h>中声明。）因此，如果n是整数，可以使用sqrt((double)n)，类似的还有pow((double)x, (double)y)等;<br>


Ref<br>
[1] <a href="http://www.ruanyifeng.com/blog/2011/11/eof.html">EOF</a><br>
