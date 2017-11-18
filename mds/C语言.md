# 在线编译器

https://www.jdoodle.com/c-online-compiler (可交互)

# C 基本信息

C was originally developed by Dennis Ritchie between 1969 and 1973 at Bell Labs.  

Stable release: C11 / December 2011 (ISO/IEC 9899:2011)

C is a compiled language - which means that in order to run it, the compiler   
(for example, GCC or Visual Studio)must take the code that we wrote, process  
it, and then create an executable file. This file can then be executed, and  
will do what we intended for the program to do.

## hello-world

```c
#include <stdio.h>

int main() {
    printf("hello-world!");

    printf("\n");
    system("pause");
    return 0;
}

```

# 变量和数据类型

## 基础数据类型

整型: 其值可正可负. 使用`char`, `int`, `short`, `long`, `long long` 定义.  
无符号整型: 其值为正. 使用`unsigned char`, `unsigned int`, `unsigned short`,  
`unsigned long`, `unsigned long long` 定义.  
浮点数: 小数. 使用`float`, `double` 定义.  

> C语言没有布尔类型.
> C语言的字符串使用数组来实现.

## 变量定义

```c
int foo;
int bar = 1;
```

> C语言的int, 一般是32位.

## 小练习

实现3个数相加.

```c
#include <stdio.h>

int main() {
    int a = 3;
    float b = 4.5;
    double c = 5.25;
    float sum;

    sum = a + b + c;

    printf("The sum of a, b, and c is %f.", sum);

    printf("\n");
    system("pause");
    return 0;
}
```

## 随机数

C语言使用`rand()`函数产生随机数, 使用`rand()`函数之前要先使用`srand(time(0))`,  
以当前时间作为种子, 否则产生的随机数将不会变化.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    srand(time(0)); //use current time as seed for random generator
    int random_variable = rand();
    printf("Random value on [0, %d]: %d\n", RAND_MAX, random_variable);
    return 0;
}
```

## 强制类型转换

一般形式如下:  
(类型名)(表达式)

```c
(int)(3.14)
(float)(8+3)
printf("%d\n", (int)(2.5)); // 2
```

## C语言数据类型最大值

# 数组

```c
int numbers[10];

/* populate the array */
numbers[0] = 10;
numbers[1] = 20;
numbers[2] = 30;
numbers[3] = 40;
numbers[4] = 50;
numbers[5] = 60;
numbers[6] = 70;

/* print the 7th number from the array, which has an index of 6 */
printf("The 7th number in the array is %d", numbers[6]);
```

```c
// 求数组平均值
#include <stdio.h>

int main() {
    int grades[3];
    int average;

    grades[0] = 80;
    grades[1] = 85;
    grades[2] = 90;

    average = (grades[0] + grades[1] + grades[2]) / 3;
    printf("The average of the 3 grades is: %d", average);

    printf("\n");
    system("pause");
    return 0;
}
```

## 动态数组空间分配

```c
#include <stdio.h>

int main () {
    int *arr;
    int len = 200;
    int i;

    arr = (int*)malloc(sizeof(int) * len);
    // 写入
    for (i=0; i<len; i++) {
        arr[i] = i;
    }

    // 读取
    for (i=0; i<len; i++) {
        printf("%d---%d\n", i, arr[i]);
    }
    free(arr);
    if (arr) {
        printf("空间已释放!");
    }

    return 0;
}

```

> C语言的数组里存放的只能是同一种数据类型.

# 字符串

如果需要修改字符串, 请把它存储与数组中.

## 字符串读写

```c
#include <stdio.h>
#include <string.h>

int main () {
    char name[] = "John Smith"; // 该字符串可读写
    printf("%s\n", name);

    strcpy(name, "hello-world");
    printf("%s\n", name);
    return 0;
}

```

## 字符串定义

字符串的定义一般使用两种方法: pointer notation, local array notation.  

```c
char * name = "John Smith"; // 该字符串只能读, 不能写

char name[] = "John Smith"; // 该字符串可读写
/* 上面的字符串定义相当于 */
char name[11] = "John Smith";
/* 字符串默认在末尾添加一个特殊符号(其值等于0), 表示字符串结束
   因此, "John Smith" 需要的长度是11 */
```

## 使用printf格式化字符串

```c
char * name = "John Smith";
int age = 27;

printf("%s is %d years old.\n", name, age);
/* prints out 'John Smith is 27 years old.' */
```

## 求字符串的长度

使用函数`strlen(str)`求字符串的长度.  

```c
#include <stdio.h>

int main() {
    char * name = "Nikhil";
    char name2[] = "John Smith";

    printf("%d\n",strlen(name)); // 6
    printf("%d\n",strlen(name2)); // 10

    printf("\n");
    system("pause");
    return 0;
}
```

## strcpy

定义: Defined in header <string.h>

原型: char *strcpy( char *dest, const char *src );

功能描述: 参数接受2个字符串, 把字符串2拷贝一份到字符串1,  
字符串1被修改, 字符串2未动. 返回字符串1的一份拷贝.

示例:

```c
#include <stdio.h>
#include <string.h> 
 
int main (void)  {
    char *src = "Take the test.";
    char dst[strlen(src) + 1]; // +1 to accomodate for the null terminator
    strcpy(dst, src);
    dst[0] = 'M'; // OK
    printf("src = %s\ndst = %s\n", src, dst);
    return 0;
}

```

## strcat

定义: Defined in header <string.h>

原型: char *strcat( char *dest, const char *src );

功能描述: 拼接字符串. 接受2个字符串作为参数, 把第2个字符串的备份附加  
到第1个字符串末尾, 第1个字符串被修改, 第2个字符串不变, 返回第1个字符串. 

示例:

```c
#include <stdio.h>
#include <string.h> 
 
int main (void)  {
    char str1[50] = "Hello ";
    char str2[50] = "World!";
    strcat(str1, str2);
    printf("%s", str1); // Hello World!
    return 0;
}

```

## strcmp

定义: Defined in header <string.h>

原型: int strcmp( const char *str1, const char *str2 );

功能描述: 比较2个字符串, 完全相等返回0, 否则根据str1 - str2的情况,  
返回1或-1. 

示例: 

```c
#include <stdio.h>
#include <string.h> 
 
int main (void)  {
    printf("%d\n", strcmp("A", "A")); // 0
    printf("%d\n", strcmp("A", "B")); // -1
    printf("%d\n", strcmp("B", "A")); // 1
    printf("%d\n", strcmp("Z", "A")); // 1
    printf("%d\n", strcmp("hello", "hello")); // 0
    return 0;
}

```

## sprintf

定义: Defined in header <stdio.h>

原型: int sprintf(char *str, const char *format, ...)

功能描述: 发送格式化输出到str所指向的字符串

### 示例1: 拼接数字和字符串

```c
#include <stdio.h>
#include <string.h> 
 
int main (void)  {
    char str[200];
    sprintf(str, "%d%s", 200, "px");
    printf("%s\n", str); // 200px

    return 0;
}

```

## sscanf

定义: Defined in header <stdio.h>

原型: int sscanf(const char *str, const char *format, ...)

功能描述:  从字符串读取格式化输入

返回值: 返回成功匹配的个数

示例: 把字符串中的数字和字符串单独拿出来

```c
#include <stdio.h>
#include <string.h>

int main (void) {
   int day, year;
   char weekday[20], month[20], dtm[100];

   strcpy( dtm, "Saturday March 25 1989" );
   sscanf( dtm, "%s %s %d %d", weekday, month, &day, &year );

   printf("%s %d, %d = %s\n", month, day, year, weekday );
   // March 25, 1989 = Saturday
    
   return(0);
}

```

示例: 去除按空格分割的指定字符串

```c
#include <stdio.h>
#include <string.h>

int main (void) {
    // elo nov
    char str[20] = "hello world";
    char res1[20];
    char res2[20];
    int suc;

    suc = sscanf(str, "%s %s", res1, res2);
    printf("suc: %d\n", suc);
    printf("res1: %s\n", res1);
    printf("res2: %s\n", res2);
    printf("r1len: %d\n", strlen(res1));
    printf("r2len: %d\n", strlen(res2));
    
   return(0);
}

```



## strtok

定义: Defined in header <string.h>

原型: char *strtok( char *str, const char *delim );

参数: 2个都是字符串(以\0结尾)

功能描述:  
该函数的功能是根据分割符分割字符串. 该函数最特殊的地方是它具有  
类似"记忆"的功能, 请看下面的示例.

### 简单示例

```c
#include <stdio.h>
#include <string.h>
#define LEN 100 

int main (void) {
    char str[LEN] = "one-two-tree-four-five";
    char *res;    // 保存分割后的结果(必须声明为指针的形式)
    char delim[LEN] = "-"; // 分隔符
    
    res = strtok(str, delim);
    printf("%s\n", res); // one
    printf("%s\n", str); // one
    // 这里的原理就是把str第一个 - 替换成 \0

    return 0;
}

```

### 第一个参数是NULL示例

```c
#include <stdio.h>
#include <string.h>
#define LEN 100 

int main (void) {
    char str[LEN] = "one-two-tree-four-five";
    char *res;    // 保存分割后的结果(必须声明为指针的形式)
    char delim[LEN] = "-"; // 分隔符
    
    res = strtok(str, delim);
    printf("%s\n", res); // one
    printf("%s\n", str); // one
    // 这里的原理就是把str第一个 - 替换成 \0

    res = strtok(NULL, delim); // 这里固定用NULL, 代表接着上次继续分割
    printf("%s\n", res); // two
    printf("%s\n", str); // one

    return 0;
}

```

### 根据指定字符分割字符串

```c
#include <stdio.h>
#include <string.h>
#define LEN 100 

int main (void) {
    char str[LEN] = "one-two";
    char *res;    // 保存分割后的结果(必须声明为指针的形式)
    char delim[LEN] = "-"; // 分隔符

    // 第1次找, 返回one
    res = strtok(str, delim);
    puts(res);

    // 第2次找, 返回two
    res = strtok(NULL, delim);
    if (res == NULL) {
        printf("NULL\n");
    } else {
        puts(res);
    }

    // 第3次找, 返回NULL
    res = strtok(NULL, delim);
    if (res == NULL) {
        printf("NULL\n");
    } else {
        puts(res);
    }

    return 0;
}

```

### 完整示例

```c
#include <stdio.h>
#include <string.h>
#define LEN 100 

int main (void) {
    char str[LEN] = "one-two-tree-four-five";
    char *res;    // 保存分割后的结果(必须声明为指针的形式)
    char delim[LEN] = "-"; // 分隔符
    int i;

    res = strtok(str, delim);
    while (res != NULL) {
        printf("%s\n", res);
        res = strtok(NULL, delim);
    }
    // 人工打印str
    for (i = 0; i < sizeof str; i++) {
        if(str[i] == '\0' && str[i + 1] != '\0') {
            printf("\\0");
        } else {
            printf("%c", str[i]);
        }
    }
/*
输出:
one
two
tree
four
five
one\0two\0tree\0four\0five\0
*/
    return 0;
}

```







## 字符串数组

C语言用二维字符数组存放多个字符串, 第二维的长度表示字符串的长度, 不能省略.  
应该最长的字符串长度定, 第一维代表要存储的字符串个数.

```c
#include <stdio.h>

int main () {
    int i;
    char week[7][20] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };

    for (i=0; i<7; i++) {
        printf("%s\n", week[i]);
    }
    return 0;
}
```

## gets

    char* gets(char *str)

gets()读取整行输入, 直至遇到换行符, 然后丢弃换行符, 存储其余字符.  
并在这些字符的末尾添加'\0', 使其称为一个C字符串

返回值: 成功返回str, 失败返回NULL

```c
#include <stdio.h>

int main () {
    char input[100];
    char *p = input;
    printf("你输入的字符串是: %s\n", gets(input));;
    while (*p != '\0') {
        putchar(*p);
        printf("\n");
        p++;
    }

    return 0;
}

```

## 打印字符串 \0 是空





# 循环

## for循环

```c
#include <stdio.h>

int main() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d\n", i);
    }

    printf("\n");
    system("pause");
    return 0;
}
```

使用循环的方法遍历数组
```c
#include <stdio.h>

int main() {
    int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int sum = 0;
    int i;

    for (i = 0; i < 10; i++) {
        sum += array[i];
    }

    /* sum now contains a[0] + a[1] + ... + a[9] */
    printf("Sum of the array is %d\n", sum);

    printf("\n");
    system("pause");
    return 0;
}
```

## while 循环

```c
int n = 0;
while (n < 10) {
    n++;
}
```

## 循环控制指令

`break`指令, 直接终止循环.  

```c
int n = 0;
while (1) {
    n++;
    if (n == 10) {
        break;
    }
}
```

`continue`指令, 跳过本次循环. 

```c
int n = 0;
while (n < 10) {
    n++;

    /* check that n is odd */
    if (n % 2 == 1) {
        /* go back to the start of the while block */
        continue;
    }

    /* we reach this code only if n is even */
    printf("The number %d is even.\n", n);
}
```

# 函数

函数只能返回1个值, 或者不返回值.  
C语言中函数的参数是按值传递的, 因此我们在函数内部无法改变函数外部的值.  
除非使用指针来实现.  

## 定义语法

```c
int foo(int bar) {
    /* do something */
    return bar * 2;
}

int main() {
    foo(1);
}
```

C语言中的函数必须先定义再使用. 推荐使用函数的方式是, 先声明再使用.  

```c
/* function declaration */
int foo(int bar);

int main() {
    /* calling foo from main */
    printf("The value of foo is %d", foo(1));
}

int foo(int bar) {
    return bar + 1;
}
```

定义没有返回值的函数, 可以使用`void`

```c
void moo() {
    /* do something and don't return a value */
}

int main() {
    moo();
}
```

## 数组作为函数参数

```c
#include <stdio.h>

void change (int* p);

int main () {
    int arr[4] = {0, 1, 2, 3};
    int i;
    int* ptr = arr;
    change(ptr);

    printf("%d\n", ptr[3]);

    for (i=0; i<4; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}

void change (int p[]) {
    p[1] = 100;
}

```

## 字符串作为函数参数

# 指针

## 什么是指针

指针一个简单的整型数, 里面存放着**内存地址**.

## 非关联化

```c
/* define a local variable a */
int a = 1;

/* define a pointer variable, and point it to a using the & operator */
int * pointer_to_a = &a;

printf("The value a is %d\n", a);
printf("The value of a is also %d\n", *pointer_to_a);
```

# typedef

语法`typedef old_type new_type`,  new_type通常用大写字母表示.

```c
typedef unsigned char BYTE;
BYTE x, y[10], * z;

typedef char * STRING;
STRING name, sign;
// 相当于 char * name, * sign;
```

# define

`#define TAXRATE 0.015`

# struct

结构是C语言中提供的一种自定义数据类型, 结构的成员可以是不同的数据类型.

## 结构的定义

结构类型定义的一般形式为:

```c
struct 结构名 {
    类型名 结构成员名1;
    类型名 结构成员名2;
};
```

先定义一个**结构类型**, 再定义一个具有这种结构类型的变量.  

struct 结构名 结构变量名;

## 结构的赋值

```c
#include <stdio.h>

// 结构类型
struct Book {
    int price;
    int page;
};

int main () {
    struct Book JaneAir; // 具体的结构变量 JaneAir

    JaneAir.page = 200; // 通过 . 来读写, 结构变量
    JaneAir.price = 48;

    printf("%d\n", JaneAir.page);
    printf("%d\n", JaneAir.price);

    return 0;
}

```

## 指向结构的指针

```c
#include <stdio.h>

// 结构类型
struct Book {
    int price;
    int page;
};

int main () {
    struct Book JaneAir;
    struct Book *BookPointer; // 指向结构的指针

    BookPointer = &JaneAir; // 把结构的地址赋给结构指针

    (*BookPointer).page = 200;
    printf("%d\n", JaneAir.page); // 200

    BookPointer->price = 300;
    printf("%d\n", JaneAir.price); // 200

    return 0;
}
```

## 指针的指针

```c
#include <stdio.h>

// 改变a的值
void changeValue (int *p, int des) {
    *p = des; // 修改传进来地址指向的那个值
}

void changePointer (int **ptr, int *des) {
    *ptr = des;
}

int main () {
    int a = 100;
    int b = 200;
    int c = 300;

    // 把a的值改成c, a = c
    changeValue(&a, c);
    printf("a = %d\n", a);

    int *p;
    p = &b;
    // 把p修改成, p = &c
    changePointer(&p, &c);
    printf("*p = %d\n", *p);

    return  0;
}


```


# C语言数据输入输出

## 实现当输入'\n'时, 循环结束

```c
#include <stdio.h>

int main () {
    int flag = 1;
    int x;
    char ch = 'x';

    while (ch != 'q') {
        scanf("%d", &x);
        printf("x = %d\n", x);
        ch = getchar();
        printf("ch = %c\n", ch);
    }

}

/*

45s125x14d255q
x = 45
ch = s
x = 125
ch = x
x = 14
ch = d
x = 255
ch = q

Process returned 0 (0x0)   execution time : 7.678 s
Press any key to continue.


*/

```

## putchar

    Defined in header <stdio.h>
    int putchar( int ch );

向屏幕输出一个字符, 参数ch会自动转换成`unsigned char`

```c
#include <stdio.h>

int main () {
    putchar('a');
    putchar('8');
    putchar('\101');
    putchar('\n');
    putchar('A');
    putchar('B');
    putchar('C');
    putchar('\n');
    putchar('\n');

    // 循环遍历 26 个字母
    char c;
    for (c='A'; c<='Z'; c++) {
        putchar(c);
    }

    return 0;
}

```

## getchar

    Defined in header <stdio.h>		
    int getchar(void);

从屏幕上读取一个字符, 成功返回读到的字符, 失败返回'EOF'

测试代码1

```c
#include <stdio.h>

int main () {
    char ch1;
    ch1 = getchar();
    /* 程序运行到这里将暂停, 等待输入一个字符, 回车表示输入结束,
       输入的字符将作为返回值, 赋给ch1 */
    printf("%c\n", ch1); // 打印ch1

    printf("%d\n", ((int)(ch1) - (int)('0')));
    // 5的ASCII码是53, 但是我就想把字符'5', 转成整型数字5,
    // 于是我作了上述转换

    return 0;
}

```

测试代码2

```c

```

## 正常输入输出

```c
#include <stdio.h>

int main() {
    char str1[20], str2[30];

    printf("请输入用户名：");
    scanf("%s", &str1);

    printf("请输入您的网站：");
    scanf("%s", &str2);

    printf("输入的用户名：%s\n", str1);
    printf("输入的网站：%s", str2);

    printf("\n");
    system("pause");
    return(0);
}
```

## printf

%f double或float
%Lf long double

格式字符串

1) 类型  
c - 字符  
d - 有符号十进制整数  
f - 十进制浮点数  
s - 字符的字符串  
u - 无符号十进制整数  
p - 指针地址  

2) 标志

```
-	    结果左对齐，右边填空格
+	    输出符号(正号或负号)
space	输出值为正时冠以空格，为负时冠以负号
#
        对o类, 在输出时加前缀o
        对x类, 在输出时加前缀0x
        对e, g, f类当结果有小数时才给出小数点
```

3) 输出最小宽度

用十进制整数来表示输出的最少位数. 若实际位数多于定义的宽度, 则按实际位数输出,  
若实际位数少于定义的宽度则补以空格或0.

4) 精度

精度格式符以" . "开头, 后跟十进制整数. 本项的意义是: 如果输出数字, 则表示小数的位数;  
如果输出的是字符, 则表示输出字符的个数;  
若实际位数大于所定义的精度数, 则截去超过的部分.  

5) 长度
长度格式符为h, l两种, h表示按短整型量输出, l表示按长整型量输出. 

参考: http://www.cnblogs.com/Alling/p/3971383.html  
http://blog.csdn.net/sinat_34009734/article/details/51646469

## scanf

%f  flaot
%lf double
%Lf long double


# 动态分配内存

在C语言中可以分别使用`malloc()`与`free()`在程序执行期间动态分配和释放内存空间,  
这两个函数定义与`stdlib.h`头文件中.

    数据类型* 指针名称 = (数据类型*)malloc(sizeof (数据类型) * n);

n是需要分配的内存空间个数.

    free(指针名称);

```c
piVal = (int*)malloc(sizeof(int)); // 指针变量指向动态分配的内存空间
free(piVal);
```

# C语言工具函数

## 数组批量赋值

`scanf()`批量赋值, 输入时, 在两个数据之间可以用一个或多个空格, tab键, 回车键分隔.  

```
#include <stdio.h>

int main () {
    int K; // 一共K个整数
    int List[100000];
    int i;

    scanf("%d", &K);
    for (i=0; i<K; i++) {
        scanf("%d", &List[i]);
    }

    for (i=0; i<K; i++) {
        printf("%d\n", List[i]);
    }

    return 0;
}

```

# C语言常见简单程序

## 设计函数求 N!

```c
#include <stdio.h>

int Fac (N) {
    /* 递归出口 */
    if (N == 1) {
        return 1;
    }

    /* 递归式子 */
    return N * Fac(N-1);
}

int main () {
    printf("%d", Fac(5));

    return 0;
}

```

# 库函数

## qsort

原型:  
void qsort( void *ptr, // 指向要排序的数组
            size_t count, // 指定数组中元素的数目
            size_t size, // 指定每个元素的长度
            int (*comp)(const void *, const void *) ); // 指向用来排序函数的函数指针

`void qsort(void *ptr, size_t count, size_t size, int (*comp)(const void *, const void *));`

### qsort简单数组排序

```c
#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *a, const void *b);

int main() {
    int ints[] = {5, 6, 10, 20, 1, 66, 20};
    int size = sizeof(ints) / sizeof(*ints);

    qsort(ints, size, sizeof(int), compare_ints);

    for (int i = 0; i < size; i++) {
        printf("%d ", ints[i]);
    }
    printf("\n");
    // output: 1 5 6 10 20 20 66

    return 0;
}

/*
    返回值: >0, 说明arg1 > arg2, 也就是arg1在arg2右边, 从小到大排序
*/
int compare_ints(const void *a, const void *b) {
    int res;
    int arg1 = *(int*)a;
    int arg2 = *(int*)b;

    if (arg1 > arg2) {
        res = 1;
    } else if (arg1 < arg2) {
        res = -1;
    } else {
        res = 0;
    }
    return res;
}

```

### C语言自带快速排序对比插入排序

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void getRandomArr (int arr[], int n);
void printArr (int arr[], int n);
void swap (int arr[], int i, int j);
void insertSort (int arr[], int n);
int compare(const void *a, const void *b);

int main () {
    int max = 40000; // 数组长度
    int sortArr1[max]; // 待排序数组
    int sortArr2[max]; // 待排序数组
    clock_t start, stop;
    double duration1;
    double duration2;

    printf("待排数据共 %d 个\n", max);

    getRandomArr(sortArr1, max); // 为待排序数组, 赋值
    start = clock(); /* 开始计时 */
    insertSort(sortArr1, max);
    stop = clock(); /* 停止计时 */
    duration1 = ((double)(stop - start)) / CLK_TCK; /* 计算运行时间 */
    printf("插入排序用时: %.4f秒\n", duration1);

    getRandomArr(sortArr2, max); // 为待排序数组, 赋值
    start = clock(); /* 开始计时 */
    qsort(sortArr2, max, sizeof(int), compare);
    stop = clock(); /* 停止计时 */
    duration2 = ((double)(stop - start)) / CLK_TCK; /* 计算运行时间 */
    printf("快速排序用时: %.4f秒\n", duration2);

    printf("快速排序是插入排序的 %d 倍\n", (int)(duration1 / duration2));

    return 0;
}

// 函数功能: 对主程序中的数组进行, 随机数赋值
// 参数: arr[] 主程序数组名称, n 数组大小
void getRandomArr (int arr[], int n) {
    int i;
    arr[0] = 0; // 默认0号下标, 值为0
    srand(time(0)); // 随机数种子
    for (i=1; i<n; i++) {
        arr[i] = rand() % 20000 + 1; // 范围[1, 20000]
    }
}

// 函数功能: 打印数组
// 参数: arr[] 需要打印的数组, n 数组大小
void printArr (int arr[], int n) {
    int i;
    for (i=0; i<n; i++) {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
    printf("\n");
}

// 函数功能: 交换数组i和j下标的2个元素
void swap (int arr[], int i, int j) {
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

// 函数功能: 完成对arr[]的排序
// 参数: arr[] 待排序的数组, n该数组的长度
void insertSort (int arr[], int n) {
    int i;
    int j;
    for (i=2; i<n; i++) {
        // 如果刚开始i > i-1, 则该元素就是本次最大值, 不用移动
        if (arr[i] > arr[i-1]) {
            continue;
        }

        for (j=i-1; j>=1; j--) { // 遍历已经排好序的元素
            // 进行两两比较, 并交换
            if (arr[j+1] < arr[j]) {
                swap(arr, j, j+1);
            }
        }
        // printArr(arr, n);
    }
}

/*
    返回值: >0, 说明arg1 > arg2, 也就是arg1在arg2右边,
     从小到大排序
*/
int compare(const void *a, const void *b) {
    int res;
    int arg1 = *(int*)a;
    int arg2 = *(int*)b;

    if (arg1 < arg2) {
        res = -1;
    } else if (arg1 > arg2) {
        res = 1;
    } else {
        res = 0;
    }
    return res;
}

```

运行结果:  
```
待排数据共 40000 个
插入排序用时: 3.8570秒
快速排序用时: 0.0080秒
快速排序是插入排序的 482 倍

Process returned 0 (0x0)   execution time : 3.983 s
Press any key to continue.
```

参考: http://devdocs.io/c/algorithm/qsort

### qsort对结构体进行排序

```c
#include <stdio.h>
#include <stdlib.h>

struct nodes {
    int x;
    int y;
    int z;
};
typedef struct nodes s_node;

void print (s_node node[], int len);
int compare (const void *a, const void *b);

int main () {
    s_node node[3];

    node[0].x = 1;
    node[1].x = 2;
    node[2].x = 3;

    node[0].y = 4;
    node[1].y = 5;
    node[2].y = 6;

    node[0].z = 10;
    node[1].z = 50;
    node[2].z = 6;

    print(node, 3);
    qsort(node, 3, sizeof(s_node), compare);
    print(node, 3);

    return 0;
}

void print (s_node node[], int len) {
    int i;
    for (i=0; i<len; i++) {
        printf("x: %d y: %d z: %d\n", node[i].x, node[i].y, node[i].z);
    }
    printf("\n");
}

// 以z为参考, 从小到大排序
int compare (const void *a, const void *b) {
    s_node arg1 = *(s_node*)a;
    s_node arg2 = *(s_node*)b;
    int res;

    if (arg1.z > arg2.z) res = 1;
    if (arg1.z < arg2.z) res = -1;
    if (arg1.z == arg2.z) res = 0;

    return res;
}

```


# sizeof

`sizeof (int)` 括号不可省

# C语言数字和字符串互相转换

## atoi - 字符串转数字

`Defined in header <stdlib.h>`  
参考: http://devdocs.io/c/string/byte/atoi

系统自带atoi使用示例:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("%d\n", atoi("6789"));
    printf("%d\n", atoi("-69"));
    printf("%d\n", atoi("-123junk"));
    printf("%d\n", atoi("0"));
    printf("%d\n", atoi("junk"));         // no conversion can be performed
    return 0;
}
/*
Output:
6789
-69
-123
0
0
*/

```

自己编写字符串转数字函数:

```c
#include <stdio.h>

int strToNum (char str[], int len);

int main() {
    int len;        // 字符串长度, 也就是数字是几位数
    char str[100];  // 存放数字字符串
    int result;     // 转换后的整数

    scanf("%d %s", &len, str);
    result = strToNum(str, len);
    printf("%d\n", result);

    return 0;
}

// 假设字符串就是数字字符串
// "6687", "11245"
// 无特殊字符, 前后无空格
int strToNum (char str[], int len) {
    int n = 0;
    int i;
    for(i=0; i<len; i++) {
        n = 10 * n + (int)(str[i] - '0');
    }

    return n;
}
/*
input: 4 5571
output: 5571

input: 6 558987
output: 558987
*/

```

## 整数转字符串 - C语言实现

```c
#include <stdio.h>
// 整数转字符串
// 假设该整数是正整数
void intToStr (int n, char str[]);

int main () {
    int n = 2841;
    char str[20];
    intToStr(n, str);
    printf(str); // "1482"

    return 0;
}

// 参数: n, 待转换的整数, str[], 保存字符串的数组
void intToStr (int n, char str[]) {
    char cur;
    char *ptr = str;
    while (n != 0) {
        cur = (char)(n % 10) + '0'; // 取最后一位
        *ptr = cur;
        ptr++;
        n = n / 10; // 删掉最后一位
    }
    *ptr = '\0';
}

```

# C语言四舍五入的实现

(int)(a + 0.5)






# 相关学习网址

https://www.learn-c.org/

http://www.cplusplus.com/reference/cstring/strncmp/

