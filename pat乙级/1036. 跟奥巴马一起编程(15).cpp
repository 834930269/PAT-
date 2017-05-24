#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){
    int N;
    char S;
    cin>>N>>S;
    for(int i=0;i<(N+1)/2;i++){
        for(int j=0;j<N;j++)
            cout<<S;
        cout<<endl;
    }
    return 0;
}
