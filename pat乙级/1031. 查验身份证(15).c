#include<stdio.h>
int main(){
    int N,APS=0,i,j=0;
    int Weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char M[11]={'1','0','X','9','8','7','6','5','4','3','2'};
    char J[19],P[3000];
    scanf("%d",&N);
    while(N--){
        int JUD=0,sum=0,mod;
        scanf("\n%s",J);
        for(i=0;i<17;i++){
            if(J[i]>='0'&&J[i]<='9'){
                sum+=(J[i]-'0')*Weight[i];
            }else{
                APS=1;
                JUD=1;
                break;
            }
        }
        if(JUD==1){
            j+=sprintf(P+j,"%s\n",J);
            continue;
        }
        mod=sum%11;
        if(J[17]!=M[mod]){
            j+=sprintf(P+j,"%s\n",J);
            APS=1;
        }
    }

    if(APS==0){
        printf("All passed\n");
    }else{
        printf("%s",P);
    }
    return 0;
}
