#include <stdio.h>

int main()
{
    int chr[128] = {0};
    char tmp, lst[7] = "PATest";

    while ((tmp = getchar()) != '\n') // ���������ַ������ۼ�ÿһ���ַ�������
        chr[tmp]++;

    for (int i = 0; i < 10000; i++)
        for (int j = 0; j < 6; j++) // �������PATest��ѭ��10000��Ϊֹ�������ַ������ᳬ��10000��
            if (chr[lst[j]]-- > 0)
                printf("%c", lst[j]);

    return 0;
}
