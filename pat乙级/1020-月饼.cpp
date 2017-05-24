#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct mooncake{
    double require;
    double weight;

    bool operator<(const mooncake &A)const{
        return weight>=A.weight;
    }
}mooncake;

int N,AR;
double value=0;

int main(){
    scanf("%d%d",&N,&AR);
    mooncake M[1001];
    for(int i=1;i<=N;i++){
        scanf("%lf",&M[i].require);
    }
    for(int i=1;i<=N;i++){
            double t;
        scanf("%lf",&t);
        M[i].weight=t/M[i].require;
    }

    sort(M+1,M+N+1);

    for(int i=1;i<=N;i++){
        if(AR>=M[i].require){
            AR-=M[i].require;
            value+=M[i].weight*M[i].require;
        }else{
            value+=M[i].weight*AR;
            break;
        }
    }
    printf("%.2lf\n",value);

    return 0;
}
