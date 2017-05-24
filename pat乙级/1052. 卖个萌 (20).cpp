#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

char *pump(char a[])//表情提取函数,识别开始的'[',记录表情,到']'结束,遇到换行符表示录入结束,返回null
{
    char c=0;
    memset(a,0,5);

    while((c=getchar())!='[')
        if(c=='\n') return NULL;
    for(int i=0;(c=getchar())!=']';i++)
        a[i]=c;
    return a;
}

int store(char db[][5],char a[])//存储读取到的表情,并返回表情个数
{
    int i=0;
    for(;pump(a)!=NULL;i++)
        strcpy(db[i],a);
    return i-1;
}

void print(char db[][11][5],int siz[])//读取请求并输出表情
{
    int a[5],tag=1;

    for(int i=0;i<5;i++){//读取一组表情请求的序号
            scanf("%d",a+i);
            a[i]-=1;//同样的,转换为0开十的序号
            if(a[i]>siz[i] || a[i]<0) tag=0;//遇到不存在的序号,标记tag为0;
    }
    if(tag)//根据请求的序号是否全存在
        printf("%s(%s%s%s)%s\n",db[0][a[0]],db[1][a[1]],db[2][a[2]],db[1][a[3]],db[0][a[4]]);
    else
        printf("Are you kidding me? @\\/@\n");
}

int main(){
    char a[5],db[3][11][5]={0};
    int n,siz[5]={0};

    for(int i=0;i<3;i++)
        siz[i]=store(db[i],a);//根据 store函数返回的值,记录改组表情的个数,从而判断请求是否合理
    siz[4]=siz[0],siz[3]=siz[1];//因为两只眼睛,两只手,所以对称

    scanf("%d",&n);
    for(int i=0;i<n;i++)//输出n次请求的表情
        print(db,siz);
    return 0;
}
