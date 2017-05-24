#include<stdio.h>
int a[11]={0};

int main(){
    for(int i=0;i<10;i++){
            int T;
            scanf("%d",&T);
            a[i]=T;
    }
    for(int i=1;i<10;i++){
        if(a[i]!=0){
            printf("%d",i);
            a[i]--;
            break;
        }
    }
    for(int i=0;i<10;i++){
        if(a[i]){
            for(int j=0;j<a[i];j++)
                printf("%d",i);
        }
    }
    printf("\n");
    return 0;
}
