#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct{
    int score;            // ��Ŀ����
    int num_Of_Correct;   // ��ȷ����Ŀ
    char choices[5];      // ��ȷ���б�
}Multi_Choice_Question;

int main()
{
    char ch, ans[250];
    int num, score, wrong_list[101] = {0}, max = 0, n, m, answer_wrong = 0;

    scanf("%d %d", &n, &m);             // ��¼ѧ��������Ŀ��
    Multi_Choice_Question qlist[m];     // ��Ŀ�б�
    memset(qlist, 0, sizeof(Multi_Choice_Question)*m); // �б��ʼ��

    // ��¼��Ŀ����ȷ���б�
    for (int i = 0; i < m; i++) {
        scanf("%d %*d %d %[^\n]", &qlist[i].score, &qlist[i].num_Of_Correct, ans);
        for (int j = 0; ans[j] != 0; j++) {
            if ('a' <= ans[j] && ans[j] <= 'e')   // ��Ϊֻ����ĸa-e����ѡ������ַ������Ժ���
                qlist[i].choices[ans[j] - 'a'] = 1;   // ����ȷѡ���ϱ��1
        }
    }

    // ���￪ʼ��ȡѧ���Ĵ𰸣����ж϶Դ�
    for (int i = 0; i < n; i++) {
        score = 0;
        for (int j = 0; j < m; j++, answer_wrong = 0, num = 0) {
            while ((ch = getchar()) != '(');   // ����ȥ����ͷ��'('�Լ�ǰ��Ŀո�
            scanf("%d %[^)]", &num, ans);      // ��ȡѡ���������Լ�����ѡ���ַ���

            if (num != qlist[j].num_Of_Correct)
                answer_wrong = 1;              // ���ѡ����������ȷ�𰸲�ͬ����һ������
            else {
                for (int k = 0; ans[k] != 0; k++) {  // �ԱȾ����
                    if ('a' <= ans[k] && ans[k] <= 'e') // ֻ������Ҫ����ַ�
                        if ((answer_wrong = !qlist[j].choices[ans[k] - 'a']))
                            break;       // ����ȡ�𰸣�������ִ����ֱ���˳��������Ϊ����
                }
            }

            if (answer_wrong)
                wrong_list[j] += 1;      // �ĵ�����˾����ĵ���Ĵ����¼�ϼ�1
            else
                score += qlist[j].score; // �����ȷ����ѧ����ô������
        }
        printf("%d\n", score);           // ���ѧ���ܷ�
    }

    for (int i = 0; i < m; i++)
        if (wrong_list[i] > max)         // ����ҳ����Ĵ������
            max = wrong_list[i];

    if (max != 0) {                      // ����������������0������������дﵽ������������
        printf("%d", max);
        for (int i = 0; i < m; i++)
            if (wrong_list[i] == max)
                printf(" %d", i+1);
    }
    else
        printf("Too simple");            // ����ȫ�ԣ���� Too simple

    return 0;
}
