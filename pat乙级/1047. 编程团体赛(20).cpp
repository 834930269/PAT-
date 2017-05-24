#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    map<int,int> mp;
    int N,Max=0,Mark;
    cin>>N;
    while(N--){
        int Q,P,S;
        cin>>Q>>P>>S;
        mp[Q]+=S;
        if(mp[Q]>Max){
            Max=mp[Q];
            Mark=Q;
        }
    }
    cout<<Mark<<" "<<Max<<endl;
    return 0;
}
