#include<iostream>
#include<algorithm>
#include<map>
#include<cstdio>
using namespace std;
int main(){
    int T[256]={0},cnt=0,PATest=0;
    char c;
    while(scanf("%c",&c)!=EOF){
        if(c=='P' || c=='A' || c=='T' || c=='e' || c=='s' || c=='t'){
            T[c]++;
            cnt++;
        }
        if(T['P']!=0&&T['A']!=0&&T['T']!=0&&T['e']!=0&&T['s']!=0&&T['t']!=0){
            T['P']--,T['A']--,T['T']--,T['e']--,T['s']--,T['t']--;
            PATest++;
            cnt-=6;
        }
    }
    while(PATest--){
        cout<<"PATest";
    }
    while(cnt>0){
        if(T['P']){
            cout<<"P";
            cnt--;
            T['P']--;
        }
        if(T['A']){
            cout<<"A";
            cnt--;
            T['A']--;
        }
        if(T['T']){
            cout<<"T";
            cnt--;
            T['T']--;
        }
        if(T['e']){
            cout<<"e";
            cnt--;
            T['e']--;
        }
        if(T['s']){
            cout<<"s";
            cnt--;
            T['s']--;
        }
        if(T['t']){
            cout<<"t";
            cnt--;
            T['t']--;
        }
    }
    cout<<endl;
    return 0;
}
