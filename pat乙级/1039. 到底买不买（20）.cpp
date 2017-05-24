#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int str[256]={0};
    int str1[256]={0};
   char T='\0';
   int cnt1=0;
   while(T!='\n'){
        scanf("%c",&T);
        str1[T]++;
        cnt1++;
   }
   T='\0';
   int cnt2=0,cnt3=0;
    while(T!='\n'){
        scanf("%c",&T);
        str[T]++;
        if(str1[T]){
            str1[T]--;
            cnt1--;
            cnt3++;
        }
        cnt2++;
   }
   if(cnt3==cnt2)
        cout<<"Yes "<<cnt1<<endl;
   else
        cout<<"No "<<cnt2-cnt3<<endl;
   return 0;
}
