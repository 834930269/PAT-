#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
    int a,b;
    int N;
    float Max=0;
    cin>>N;
    while(N--){
        cin>>a>>b;
        float r=sqrt(a*a+b*b);
        if(r>Max) Max=r;
    }
    printf("%.2f\n",Max);
    return 0;
}
