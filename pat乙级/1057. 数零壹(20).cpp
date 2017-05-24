#include<stdio.h>
#include<ctype.h>

int main()
{
    char a[100010] = {0}, list[255] = {0};
    int sum = 0, count[2] = {0};

    for (int i = 'a'; i <= 'z'; i++)  // 做一个字母与数字的映射表
        list[i] = i - 'a' + 1;

    scanf("%[^\n]", a);               // 用这种读取方式可以一直读取到换行符结束
    for (int i = 0; a[i] != 0; i++) { // 遍历输入的字符串
        a[i] = tolower(a[i]);         // 如果是字母则转为小写
        sum += list[a[i]];            // 通过查表获得对应数字，并累计
    }

    for (; sum > 0; sum >>= 1) {      // 每次循环右移一位
        count[sum & 1]++;             // 取末位的数字，在统计量上加1
    }

    printf("%d %d", count[0], count[1]);
    return 0;
}
