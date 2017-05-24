#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef long long LL;

LL GR,SR,KR;

void solve(LL G,LL S,LL K,LL G2,LL S2,LL K2){
    if(K2<K){
        KR=K2+29-K;
        if(S2==0){
            S2=16;
            G2--;
        }else{
            S2--;
        }
    }else{
        KR=K2-K;
    }

    if(S2<S){
        SR=S2+17-S;
        G2--;
    }else{
        SR=S2-S;
    }

    GR=G2-G;
}

int main(){
  LL Galleon1,Sickle1,Knut1;
  LL Galleon2,Sickle2,Knut2;
  int Jud=0;
  scanf("%lld.%lld.%lld",&Galleon1,&Sickle1,&Knut1);
  scanf("%lld.%lld.%lld",&Galleon2,&Sickle2,&Knut2);
   if(Galleon1>Galleon2)
        Jud=1;
    if(Galleon1==Galleon2  &&  Sickle1 > Sickle2)
        Jud=1;
    if(Galleon1==Galleon2 &&  Sickle1==Sickle2  &&  Knut1>Knut2)
        Jud=1;
    if(Jud){
        cout<<"-";
        solve(Galleon2,Sickle2,Knut2,Galleon1,Sickle1,Knut1);
    }else{
        solve(Galleon1,Sickle1,Knut1,Galleon2,Sickle2,Knut2);
    }
    cout<<GR<<"."<<SR<<"."<<KR<<endl;
    return 0;
}
