#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef struct{//�洢����ѧ����Ϣ�Ľṹ��
    char ch[10];
    int H;
}PSN;

int comp(const void *a,const void *b){//�ȽϺ���,�Ȱ����,���ֵ���
    PSN *c=(PSN*)a,*d=(PSN*)b;
    if(d->H-c->H!=0)return d->H-c->H;
    else return strcmp(c->ch,d->ch);
}
int main(){
    int n,row;
    scanf("%d %d",&n,&row);
    PSN psn[n];//������Ҫ����ṹ������
    for(int i=0;i<n;i++)
            scanf("%s %d",psn[i].ch,&psn[i].H);
    qsort(psn,n,sizeof(PSN),comp);//��Ҫ������

    int rs=n%row,re=n/row,pe=1;//reΪÿ�Ż�������,rsΪ�����������,peΪ�ڶ����
    int pleft,pright,width;
    char *tmp[n/row+1];

    for(int i=0,j=0;i<row;i++,pe=1,rs=0){
        width=re+rs;//��һ���ɻ�������,���϶�����������,��һ��ѭ��rs��0,��ȱ�Ϊ��������
        pright=(re+rs)/2;//��Ŀ��Ҫ���m/2+1,��Ϊ��Ϊ�����±�ʹ��,��0��ʼ,���Բ���+1
        pleft=pright-1;
        for(int i=0;i<width;i++){//ͨ���ڶ�pe,�������ݴ���λ��
                if(pe==1) tmp[pright++]=psn[j++].ch;
                if(pe==-1)tmp[pleft--]=psn[j++].ch;
                pe*=-1;
        }
        printf("%s",tmp[0]);
        for(int i=1;i<width;i++)//˳�����
                printf(" %s",tmp[i]);
        printf("\n");
    }
    return 0;
}
