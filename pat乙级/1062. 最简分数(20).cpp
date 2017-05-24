#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int gcd(int a,int b){
    return a%b==0?b:gcd(b,a%b);
}

int main(){
    int N1,M1,N2,M2;
    scanf("%d/%d %d/%d",&N1,&M1,&N2,&M2);
    int K;
    scanf("%d",&K);
    if(N1>N2){
        swap(N1,N2);
        swap(M1,M2);
    }
    float a=1.0*N1/M1,b=1.0*N2/M2,r;
    int flag=0;
    for(int i=1;i<K;i++){
        r=1.0*i/K;
        if(r>a&&r<b){
            if(gcd(i,K)==1){
                if(flag)
                    printf(" ");
                printf("%d/%d",i,K);
                flag=1;
            }
        }
    }
    cout<<endl;
    return 0;
}
