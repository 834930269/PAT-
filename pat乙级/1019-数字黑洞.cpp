#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int dsc,dw;
void solve(int N){
    int s[4];
    s[0]=N/1000;
    s[1]=N/100%10;
    s[2]=N/10%10;
    s[3]=N%10;
    sort(s,s+4);
    dsc=s[0]*1000+s[1]*100+s[2]*10+s[3];
    dw=s[3]*1000+s[2]*100+s[1]*10+s[0];
}

int main(){
    int n,s;
    scanf("%d",&n);
    if((n/1000==n/100%10)&&(n/1000==n/10%10)&&(n/1000==n%10)){
        printf("%04d - %04d = 0000\n",n,n);
        return 0;
    }
    do{
        solve(n);
        s=dw-dsc;
        printf("%04d - %04d = %04d\n",dw,dsc,s);
        n=s;
    }while(s!=6174);
    return 0;
}
