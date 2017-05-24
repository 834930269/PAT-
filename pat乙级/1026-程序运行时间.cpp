#include<stdio.h>
using namespace std;
const int CLK_TCK=100;
int main(){
    int C1,C2;
    scanf("%d%d",&C1,&C2);
    int p=(double)(C2-C1)/CLK_TCK+0.5;
    int h=p/3600;
    int min=(p-h*3600)/60;
    int second=p-h*3600-min*60;
    printf("%02d:%02d:%02d\n",h,min,second);//02d∏Ò Ωøÿ÷∆
}
