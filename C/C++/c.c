#include <stdio.h>

// gcc -o demo.exe -std=c18 c.c

// 占位符 
void demo_Printf(void)
{
    int x = 6;
    printf("浮点数 %a\n", 0.12345678);
    printf("浮点数 %A\n", 0.12345678);
    printf("字符 %c \n", 'C');
    printf("十进制整数 %d \n", 2);
    printf("整数 %i \n", 4);
    printf("小数float+double %f \n", 5.6789);
    printf("\n指针 %p \n", x);
    printf("字符串 %s\n", "abcdefg");
    printf("无符号整数（unsigned int） %u\n", 4567);
    printf("八进制整数 %o，显示前缀 %#o \n", 345,345);
    printf("\n指针 %p \n", &x);
    printf("字符串 %s\n", "abcdefg");
    printf("无符号整数（unsigned int） %u\n", 4567);
    printf("十六进制整数 %x,前缀 %#x，前缀 %#X \n", 5678,5678,5678);
    printf("返回某种数据类型或某个值占用的字节数量size_t类型 %zd \n", sizeof(678.24556));
    printf("输出一个百分号%% \n");

    printf("科学计数法的浮点数 %e \n", 0.00000034567);
    printf("科学计数法的浮点数 %E \n", 0.00000034567);

    printf("6个有效数字的浮点数。整数部分一旦超过6位，就会自动转为科学计数法，指数部分的e为小写 %g \n", 678901234.012345678901);
    printf("等同于 g ，唯一的区别是指数部分的E为大写 %G \n", 678901234.012345678901);
    printf("十进制 short int 类型 %hd \n", 70);
    printf("八进制 short int 类型 %ho \n", 80);
    printf("十六进制 short int 类型  %hx \n", 90);
    printf("unsigned short int 类型 %hu \n", 100);
    printf("十进制 long int 类型 %ld \n", 20000);
    printf("八进制 long int 类型 %lo \n", 300);
    printf("十六进制 long int 类型 %lx \n", 4000);
    printf("unsigned long int 类型  %lu \n", 500000);
    printf("十进制 long long int 类型 %lld \n", 6000000);
    printf("八进制 long long int 类型 %llo \n", 70000000);
    printf("十六进制 long long int 类型 %llx \n", 80000000);
    printf("unsigned long long int 类型 %llu\n", 90123456);
    printf("科学计数法表示的 long double 类型浮点数 %Le \n", 123456789.012345678);
    printf("long double 类型浮点数 %Lf \n", 234567890.0123456789);
    printf("已输出的字符串数量。该占位符本身不输出，只将值存储在指定变量之中 %n \n", "c");

    printf("限定宽度至少为5位，空格补齐 %5d\n", 789);
    printf("总是显示正负号 %+d\n", -89);
    printf("限定小数位数，自动补 %.2f %.2f\n", 0.5, 0.678);
    printf("输出部分字符串,指定长度 %.5s\n", "abcdefghigq");
}

// 关键字
// auto, break, case, char, const, continue, default, 
// do, double, else, enum, extern, float, for, goto,
//  if, inline, int, long, register, restrict, 
//  return, short, signed, sizeof, static, struct,
//   switch, typedef, union, unsigned, void, volatile, while

int main(void)
{
    printf("hello %i  \n", 21);
    demo_Printf();
    return 0;
}
