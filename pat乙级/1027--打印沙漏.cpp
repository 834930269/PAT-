#include <stdio.h>

int main()
{
    int tapin, n = 0, m;
    char c[2] = {0,' '};
    scanf("%d %c", &tapin, c);

    for (int i = 1; n == 0; i++) // ��������ɴ�ӡ���������ϰ�Σ�
        if (2*i*i-1 > tapin)
            n = i - 1;
    m = tapin - (2*n*n-1); // �����ܹ���Ҫ���ַ���

    for (int i = 0, ver = 0; ver < 2*n-1; ver++) { // ��ӡɳ©
        i = ver >= n ? 2*n-2-ver : ver; // ͨ���������ʽ����i����������
        for (int j = 0; j < 2*n-1-i; j++)
            printf("%c", c[j<i]);
        printf("\n");
    }

    printf("%d", m);

    return 0;
}
