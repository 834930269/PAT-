#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

char *pump(char a[])//������ȡ����,ʶ��ʼ��'[',��¼����,��']'����,�������з���ʾ¼�����,����null
{
    char c=0;
    memset(a,0,5);

    while((c=getchar())!='[')
        if(c=='\n') return NULL;
    for(int i=0;(c=getchar())!=']';i++)
        a[i]=c;
    return a;
}

int store(char db[][5],char a[])//�洢��ȡ���ı���,�����ر������
{
    int i=0;
    for(;pump(a)!=NULL;i++)
        strcpy(db[i],a);
    return i-1;
}

void print(char db[][11][5],int siz[])//��ȡ�����������
{
    int a[5],tag=1;

    for(int i=0;i<5;i++){//��ȡһ�������������
            scanf("%d",a+i);
            a[i]-=1;//ͬ����,ת��Ϊ0��ʮ�����
            if(a[i]>siz[i] || a[i]<0) tag=0;//���������ڵ����,���tagΪ0;
    }
    if(tag)//�������������Ƿ�ȫ����
        printf("%s(%s%s%s)%s\n",db[0][a[0]],db[1][a[1]],db[2][a[2]],db[1][a[3]],db[0][a[4]]);
    else
        printf("Are you kidding me? @\\/@\n");
}

int main(){
    char a[5],db[3][11][5]={0};
    int n,siz[5]={0};

    for(int i=0;i<3;i++)
        siz[i]=store(db[i],a);//���� store�������ص�ֵ,��¼�������ĸ���,�Ӷ��ж������Ƿ����
    siz[4]=siz[0],siz[3]=siz[1];//��Ϊ��ֻ�۾�,��ֻ��,���ԶԳ�

    scanf("%d",&n);
    for(int i=0;i<n;i++)//���n������ı���
        print(db,siz);
    return 0;
}
