#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long LL;

int main(){
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    double sum=0;
    for(int i=1;i<=N;i++){
        double Q;
        cin>>Q;
        sum+=Q*(N-i+1)*i;
    }
    printf("%.2lf\n",sum);
    return 0;
}
