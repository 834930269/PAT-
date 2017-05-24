#include<stdio.h>

int reg[10]={0};


int main(){
    char T;
    scanf("%c",&T);
    while(T!='\n'){
        reg[T-'0']++;
        scanf("%c",&T);
    }
    for(int i=0;i<10;i++){
        if(reg[i]!=0)
            printf("%d:%d\n",i,reg[i]);
    }
    return 0;
}
