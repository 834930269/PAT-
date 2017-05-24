#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int main(){
    string A,B;
    char DA,DB;
    cin>>A>>DA>>B>>DB;
    int sumA=0,i=0,t=1;
    while(A[i]){
        if(A[i]==DA){
            sumA=sumA+t*(DA-'0');
            t*=10;
        }
        i++;
    }
    int sumB=0,j=0,p=1;
    while(B[j]){
        if(B[j]==DB){
            sumB=sumB+p*(DB-'0');
            p*=10;
        }
        j++;
    }
    cout<<sumB+sumA<<'\n';
    return 0;

}
