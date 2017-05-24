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

int compare(const void *a,const void *b){//任意类型,前与后比较,qsort比较模式,大,返回整数,小,返回非正整数
    life *c=(life*)a,*d=(life*)b;
    if(c->year!=d->year) return c->year-d->year;
    else if(c->month!=d->month) return c->month-d->month;
    else return c->day-d->day;
}//qsort返回的是int形的

int main(){
    int n;
    scanf("%d",&n);
    life tol[n],upper={"upper",2014,9,6},lower={"lower",1814,9,6};
    int cnt=0;
    for(int i=0;i<n;i++){
        scanf("%s %d/%d/%d",tol[cnt].name,&tol[cnt].year,&tol[cnt].month,&tol[cnt].day);
        if(compare(&tol[cnt],&upper)>0||compare(&tol[cnt],&lower)<0)continue;//不该存于世的年龄
        cnt++;
    }//只记录有效值,用cnt控制
    qsort(tol,cnt,sizeof(life),compare);//大的在前,小的在后
    if(cnt==0)printf("0");//输入整数不为0,但记录的值可能为0个
    else
    printf("%d %s %s",cnt,tol[0].name,tol[cnt-1].name);

    return 0;

}
