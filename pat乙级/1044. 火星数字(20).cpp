#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const char list[110] = "tretjan feb mar apr may jun jly aug sep oct nov dec ----tam hel maa huh tou kes hei elo syy lok mer jou ";

void trans_mtoe(char chr[])
{
    int high = 0, low = 0, mark = (int)strlen(chr);
    if (mark > 5) { // 因为火星数字多数为三字节，所以这里判断字符串长度大于5的是两位数，小于5的是一位数
        chr[3] = 0;
        high = (int)((strstr(list+52, chr)) - (list+52)) / 4; // 在对照表中查找“十位”
        low = (int)((strstr(list, chr+4)) - list) / 4; // 在对照表中查找“个位”
    }
    else {
        low = (int)((strstr(list, chr)) - list) / 4; // 查找“个位”
        if (low > 12) { // 如果查找个位时，发现个位数字在“高位数”中，则说明是省略了个位的写法
            high = low - 13;
            low = 0;
        }
    }
    sprintf(chr, "%d", high * 13 + low);
}

void trans_etom(char chr[]) // 地球转火星是很常用的写法，取出13进制的高低位，分情况讨论输出就好了
{
    int num = atoi(chr), high = num / 13, low = num % 13;
    if (high != 0) {
        sprintf(chr, "%.3s", (list+52) + high*4);
        if (low != 0)
            sprintf(chr+3, " ");
        sprintf(chr+4, "%.3s", list + low*4);
    }
    else {
        if (low != 0)
            sprintf(chr, "%.3s", list + low*4);
        else
            sprintf(chr, "%.4s", list);
    }
}

int main()
{
    int n;
    char chr[10] = {0};
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        while (getchar() != '\n');
        scanf("%[^\n]", chr); // 逐行读取输入
        if (isdigit(chr[0])) // 通过首位是不是数字，判断是地球文还是火星文
            trans_etom(chr); // 是地球文的话进行 地球-->火星 转换
        else trans_mtoe(chr); // 否则进行 火星-->地球 转化
        printf("%s\n", chr); // 输出
    }

    return 0;
}
