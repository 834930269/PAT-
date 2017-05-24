#include <stdio.h>

typedef struct frac_{long n, d, s;} FC;
// 求最大公约数的函数
long gcd(long a, long b) {return b == 0 ? a : gcd(b, a % b);}
// 分数处理函数
FC hand(FC a)
{
    if (a.n < 0) {a.s *= -1; a.n *= -1;} // 如果分子为负，将符号赋给符号变量，分子取正值
    long tmp = gcd(a.n, a.d);
    a.n /= tmp;
    a.d /= tmp; // 约分
    return a;
}
// 单个分数输出函数
void prt_fc(FC a)
{
    if (a.d == 0)
        printf("Inf"); // 如果分母为0，输出Inf
    else {
        long i = a.n / a.d; // 提取整数部分
        a.n = a.n % a.d; // 分数化为真分数
        a = hand(a); // 约分
        if (a.n == 0 && i == 0) printf("0"); // 如果整数小数部分均为0，输出0
        else {
            if (a.s == -1) printf("(-"); // 如果符号为负，则添加括号和负号
            if (i != 0) printf("%ld", i);
            if (i != 0 && a.n != 0) printf(" ");
            if (a.n != 0) printf("%ld/%ld", a.n, a.d);
            if (a.s == -1) printf(")");
        }
    }
}
// 算式输出函数
void prt_eq(FC a, FC b, char c, FC (*fig)(FC, FC))
{
    prt_fc(a);
    printf(" %c ", c);
    prt_fc(b);
    printf(" = ");
    prt_fc(hand((*fig)(a, b)));
    printf("\n");
}
// 计算函数，加减乘除
FC plus (FC a, FC b) {return (FC){a.s*a.n*b.d + b.s*b.n*a.d, a.d*b.d, 1};}
FC sub  (FC a, FC b) {return (FC){a.s*a.n*b.d - b.s*b.n*a.d, a.d*b.d, 1};}
FC multi(FC a, FC b) {return (FC){a.n*b.n, a.d*b.d, a.s*b.s};}
FC divis(FC a, FC b) {return (FC){a.n*b.d, a.d*b.n, a.s*b.s};}

int main()
{
    FC a = {0, 0, 1}, b = {0, 0, 1}, (*fig[])(FC, FC) = {plus, sub, multi, divis};
    char c[5] = "+-*/";

    scanf("%ld/%ld %ld/%ld", &a.n, &a.d, &b.n, &b.d); // 读取分数a、b
    for (int i = 0; i < 4; i++)
        prt_eq(hand(a), hand(b), c[i], fig[i]); // 将处理过的分数，计算符号，计算函数、传递给算式输出函数

    return 0;
}
