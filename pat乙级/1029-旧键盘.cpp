#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;
int main(){
string A,B;
string P;
set<char> T;
int i=0,j=0;
getline(cin,A);
getline(cin,B);
set<char>::iterator it;
while(A[i]){
    if(A[i]>='a'&&A[i]<='z'){
            A[i]=A[i]-('a'-'A');
    }
    if(B[j]>='a'&&B[j]<='z'){
            B[j]=B[j]-('a'-'A');
    }
    if(A[i]!=B[j]){
        it=T.find(A[i]);
        if(it!=T.end()){
            i++;
            continue;
        }else{
            T.insert(A[i]);
            P+=A[i];
            i++;
        }
    }else{
        j++;i++;
    }
}

cout<<P;

return 0;
}
