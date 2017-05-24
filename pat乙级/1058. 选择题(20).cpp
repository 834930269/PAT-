#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct{
    int score;            // 题目分数
    int num_Of_Correct;   // 正确答案数目
    char choices[5];      // 正确答案列表
}Multi_Choice_Question;

int main()
{
    char ch, ans[250];
    int num, score, wrong_list[101] = {0}, max = 0, n, m, answer_wrong = 0;

    scanf("%d %d", &n, &m);             // 记录学生数与题目数
    Multi_Choice_Question qlist[m];     // 题目列表
    memset(qlist, 0, sizeof(Multi_Choice_Question)*m); // 列表初始化

    // 记录题目的正确答案列表
    for (int i = 0; i < m; i++) {
        scanf("%d %*d %d %[^\n]", &qlist[i].score, &qlist[i].num_Of_Correct, ans);
        for (int j = 0; ans[j] != 0; j++) {
            if ('a' <= ans[j] && ans[j] <= 'e')   // 因为只有字母a-e才是选项，其他字符都可以忽略
                qlist[i].choices[ans[j] - 'a'] = 1;   // 在正确选项上标记1
        }
    }

    // 这里开始读取学生的答案，并判断对错
    for (int i = 0; i < n; i++) {
        score = 0;
        for (int j = 0; j < m; j++, answer_wrong = 0, num = 0) {
            while ((ch = getchar()) != '(');   // 这里去掉开头的'('以及前面的空格
            scanf("%d %[^)]", &num, ans);      // 读取选项数量，以及具体选项字符串

            if (num != qlist[j].num_Of_Correct)
                answer_wrong = 1;              // 如果选项数量与正确答案不同，则一定错误
            else {
                for (int k = 0; ans[k] != 0; k++) {  // 对比具体答案
                    if ('a' <= ans[k] && ans[k] <= 'e') // 只检查符合要求的字符
                        if ((answer_wrong = !qlist[j].choices[ans[k] - 'a']))
                            break;       // 查表获取答案，如果出现错误答案直接退出，并标记为错误
                }
            }

            if (answer_wrong)
                wrong_list[j] += 1;      // 哪道题错了就在哪道题的错误记录上加1
            else
                score += qlist[j].score; // 如果正确，该学生获得此题分数
        }
        printf("%d\n", score);           // 输出学生总分
    }

    for (int i = 0; i < m; i++)
        if (wrong_list[i] > max)         // 查表找出最大的错误次数
            max = wrong_list[i];

    if (max != 0) {                      // 如果最大错误次数大于0，遍历输出所有达到这个次数的题号
        printf("%d", max);
        for (int i = 0; i < m; i++)
            if (wrong_list[i] == max)
                printf(" %d", i+1);
    }
    else
        printf("Too simple");            // 否则全对，输出 Too simple

    return 0;
}
