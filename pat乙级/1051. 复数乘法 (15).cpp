#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
#define exp 1e-2
int main(){
    double R1,P1,R2,P2;
    cin>>R1>>P1>>R2>>P2;
    double R=R1*R2,P=P1+P2;
    double A=R*cos(P),B=R*sin(P),T=0;
    if(fabs(B)<exp&&fabs(A)>exp){
        printf("%.2lf+0.00i\n",A);
    }else if(fabs(B)>exp&&fabs(A)<exp){
        printf("0.00%+.2lfi",B);
    }else if(fabs(B)>exp&&fabs(A)>exp){
        printf("%.2lf%+.2lfi\n",A,B);
    }else{
        printf("0\n");
    }

    return 0;
}
