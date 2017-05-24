#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;
typedef struct life{
    char name[10];
    int year;
    int month;
    int day;
}life;

int compare(const void *a,const void *b){//��������,ǰ���Ƚ�,qsort�Ƚ�ģʽ,��,��������,С,���ط�������
    life *c=(life*)a,*d=(life*)b;
    if(c->year!=d->year) return c->year-d->year;
    else if(c->month!=d->month) return c->month-d->month;
    else return c->day-d->day;
}//qsort���ص���int�ε�

int main(){
    int n;
    scanf("%d",&n);
    life tol[n],upper={"upper",2014,9,6},lower={"lower",1814,9,6};
    int cnt=0;
    for(int i=0;i<n;i++){
        scanf("%s %d/%d/%d",tol[cnt].name,&tol[cnt].year,&tol[cnt].month,&tol[cnt].day);
        if(compare(&tol[cnt],&upper)>0||compare(&tol[cnt],&lower)<0)continue;//���ô�����������
        cnt++;
    }//ֻ��¼��Чֵ,��cnt����
    qsort(tol,cnt,sizeof(life),compare);//�����ǰ,С���ں�
    if(cnt==0)printf("0");//����������Ϊ0,����¼��ֵ����Ϊ0��
    else
    printf("%d %s %s",cnt,tol[0].name,tol[cnt-1].name);

    return 0;

}
