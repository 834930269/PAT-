#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int mer[256]={0};
    char T='\0';
    while(T!='\n'){
            scanf("%c",&T);
            if(T=='\n')
                break;
            if(T>='A'&&T<='Z'){
                mer[T-'A'+'a']=1;
                mer[T]=1;
            }else
                mer[T]=1;
    }
    char str[100001];
    T='\0';
    int i=0;
    while(scanf("%c",&T)!=EOF){
        if(!mer[T]){
            if(T>='A'&&T<='Z'){
                if(!mer['+'])
                    str[i++]=T;
            }else{
                str[i++]=T;
            }
        }
    }
    if(i==0)
        cout<<endl;
    else
        cout<<str;
    return 0;
}
