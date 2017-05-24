#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const char list[110] = "tretjan feb mar apr may jun jly aug sep oct nov dec ----tam hel maa huh tou kes hei elo syy lok mer jou ";

void trans_mtoe(char chr[])
{
    int high = 0, low = 0, mark = (int)strlen(chr);
    if (mark > 5) { // ��Ϊ�������ֶ���Ϊ���ֽڣ����������ж��ַ������ȴ���5������λ����С��5����һλ��
        chr[3] = 0;
        high = (int)((strstr(list+52, chr)) - (list+52)) / 4; // �ڶ��ձ��в��ҡ�ʮλ��
        low = (int)((strstr(list, chr+4)) - list) / 4; // �ڶ��ձ��в��ҡ���λ��
    }
    else {
        low = (int)((strstr(list, chr)) - list) / 4; // ���ҡ���λ��
        if (low > 12) { // ������Ҹ�λʱ�����ָ�λ�����ڡ���λ�����У���˵����ʡ���˸�λ��д��
            high = low - 13;
            low = 0;
        }
    }
    sprintf(chr, "%d", high * 13 + low);
}

void trans_etom(char chr[]) // ����ת�����Ǻܳ��õ�д����ȡ��13���Ƶĸߵ�λ���������������ͺ���
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
        scanf("%[^\n]", chr); // ���ж�ȡ����
        if (isdigit(chr[0])) // ͨ����λ�ǲ������֣��ж��ǵ����Ļ��ǻ�����
            trans_etom(chr); // �ǵ����ĵĻ����� ����-->���� ת��
        else trans_mtoe(chr); // ������� ����-->���� ת��
        printf("%s\n", chr); // ���
    }

    return 0;
}
