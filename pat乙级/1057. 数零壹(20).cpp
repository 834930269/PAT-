#include<stdio.h>
#include<ctype.h>

int main()
{
    char a[100010] = {0}, list[255] = {0};
    int sum = 0, count[2] = {0};

    for (int i = 'a'; i <= 'z'; i++)  // ��һ����ĸ�����ֵ�ӳ���
        list[i] = i - 'a' + 1;

    scanf("%[^\n]", a);               // �����ֶ�ȡ��ʽ����һֱ��ȡ�����з�����
    for (int i = 0; a[i] != 0; i++) { // ����������ַ���
        a[i] = tolower(a[i]);         // �������ĸ��תΪСд
        sum += list[a[i]];            // ͨ������ö�Ӧ���֣����ۼ�
    }

    for (; sum > 0; sum >>= 1) {      // ÿ��ѭ������һλ
        count[sum & 1]++;             // ȡĩλ�����֣���ͳ�����ϼ�1
    }

    printf("%d %d", count[0], count[1]);
    return 0;
}
