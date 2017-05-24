#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int N,D,K,Empty=0,May=0;
    double e,ek;
    cin>>N>>e>>D;
    int T=N;
    while(T--){
        int cnt=0,flag=0;
        cin>>K;
        for(int i=0;i<K;i++){
            cin>>ek;
            if(ek<e)
                cnt++;
        }
        if(cnt>K/2){
                May++;
                flag=1;
        }
        if(K>D&&flag){
                May--;
                Empty++;
        }
    }
    printf("%.1lf%% %.1lf%%\n",100.0*May/N,100.0*Empty/N);

    return 0;
}
