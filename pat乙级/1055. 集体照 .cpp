#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef struct{//存储单个学生信息的结构体
    char ch[10];
    int H;
}PSN;

int comp(const void *a,const void *b){//比较函数,先按身高,后按字典序
    PSN *c=(PSN*)a,*d=(PSN*)b;
    if(d->H-c->H!=0)return d->H-c->H;
    else return strcmp(c->ch,d->ch);
}
int main(){
    int n,row;
    scanf("%d %d",&n,&row);
    PSN psn[n];//根据需要申请结构体数组
    for(int i=0;i<n;i++)
            scanf("%s %d",psn[i].ch,&psn[i].H);
    qsort(psn,n,sizeof(PSN),comp);//按要求排序

    int rs=n%row,re=n/row,pe=1;//re为每排基础人数,rs为多出来的人数,pe为摆动标记
    int pleft,pright,width;
    char *tmp[n/row+1];

    for(int i=0,j=0;i<row;i++,pe=1,rs=0){
        width=re+rs;//第一排由基础人数,加上多出来的人组成,第一次循环rs置0,宽度变为基础人数
        pright=(re+rs)/2;//题目中要求的m/2+1,因为作为数组下标使用,从0开始,所以不用+1
        pleft=pright-1;
        for(int i=0;i<width;i++){//通过摆动pe,控制数据存入位置
                if(pe==1) tmp[pright++]=psn[j++].ch;
                if(pe==-1)tmp[pleft--]=psn[j++].ch;
                pe*=-1;
        }
        printf("%s",tmp[0]);
        for(int i=1;i<width;i++)//顺序输出
                printf(" %s",tmp[i]);
        printf("\n");
    }
    return 0;
}
