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


Ref<br>
[1] <a href="http://www.ruanyifeng.com/blog/2011/11/eof.html">EOF</a><br>
