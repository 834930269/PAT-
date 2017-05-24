#include<stdio.h>
#include<stack>
using namespace std;
int main(){
    int A,B;
    long int sum;
    stack<int> s;
    scanf("%d%d",&A,&B);
    int D;
    scanf("%d",&D);
    sum=A+B;
    if(sum==0)printf("0");//sum¿ÉÄÜÎª0
    while(sum){
        s.push(sum%D);
        sum/=D;
    }
    while(!s.empty()){
        printf("%d",s.top());
        s.pop();
    }
    printf("\n");
    return 0;
}
