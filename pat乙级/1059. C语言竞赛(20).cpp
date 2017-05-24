#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int map[10001]={0};

//Àÿ–‘≤‚ ‘
bool is_prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)
            return false;
    }
    return n!=1;//1 «¿˝Õ‚
}

int main(){
    int N,cnt=1;
    int award[10001]={0};
    cin>>N;
    while(N--){
        int sno;
        cin>>sno;
        map[sno]=cnt;
        cnt++;
    }
    cin>>N;
    while(N--){
        int sno;
        cin>>sno;
        if(map[sno]==0)
            printf("%04d: Are you kidding?\n",sno);
        else{
            if(award[sno])
                printf("%04d: Checked\n",sno);
            else if(map[sno]==1)
                printf("%04d: Mystery Award\n",sno);
            else if(is_prime(map[sno]))
                printf("%04d: Minion\n",sno);
            else
                printf("%04d: Chocolate\n",sno);
        }
        award[sno]=1;
    }
    return 0;
}
