#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main(){
    int  ma[256]={0},Max=0,Mark=0;
    char c;
    while(scanf("%c",&c)!=EOF){
        if(c>='A'&&c<='Z')
            c=c-'A'+'a';
        if(c>='a'&&c<='z'){
            ma[c]++;
            if(ma[c]>Max){
                Max=ma[c];
                Mark=c;
            }else if(ma[c]==Max && c<Mark){
                Mark=c;
            }
        }
    }
    cout<<(char)Mark<<" "<<Max<<endl;
    return 0;
}
