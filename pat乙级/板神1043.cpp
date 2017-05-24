#include <stdio.h>

int main()
{
    int chr[128] = {0};
    char tmp, lst[7] = "PATest";

    while ((tmp = getchar()) != '\n') // 遍历输入字符串，累计每一个字符个数。
        chr[tmp]++;

    for (int i = 0; i < 10000; i++)
        for (int j = 0; j < 6; j++) // 遍历输出PATest，循环10000次为止（输入字符串不会超过10000）
            if (chr[lst[j]]-- > 0)
                printf("%c", lst[j]);

    return 0;
}
