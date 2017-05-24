#include<iostream>
#include<algorithm>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
int main(){
    int N,M;
    int score[101],key[101]={0};
    cin>>N>>M;
    FOR(i,1,M)
        cin>>score[i];
    FOR(i,1,M)
        cin>>key[i];
    FOR(i,1,N){
        int sum=0;
        FOR(j,1,M){
            int ans;
            cin>>ans;
            if(key[j]==ans)
                sum+=score[j];
        }
        cout<<sum<<endl;
    }
    return 0;
}
