#include<stdio.h>

int main() {
    int n = 0, sum = 0, a[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) { // �����������ֵĺ�
        scanf("%d", a+i);
        sum += a[i];
    }

    sum *= n - 1;

    printf("%d", sum * 11);
    return 0;
}
