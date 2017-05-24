#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef unsigned long long LL;

int main(){
    ios::sync_with_stdio(false);
    char T[100001];
    char P='\0';
    LL cp=0,cpa=0,cpat=0,i=0;

    while(P!='\n'){
        scanf("%c",&P);
        if(P=='\n')
            break;
        T[i++]=P;
        if(P=='P'){
            cp++;
        }
        if(cp!=0 && P=='A'){
            cpa+=cp;
        }
        if(cpa!=0 && P=='T'){
            cpat+=cpa;
        }
    }
    cout<<cpat%1000000007<<endl;
    return 0;
}
