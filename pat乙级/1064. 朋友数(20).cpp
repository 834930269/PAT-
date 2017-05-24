#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    map<int,int> mp;
    int N;
    cin>>N;
    while(N--){
        int X,F=0;
        cin>>X;
        while(X>0){
            F+=X%10;
            X/=10;
        }
        mp[F]++;
    }
    map<int,int>::iterator it;
    cout<<mp.size()<<endl;
    it=mp.begin();
    cout<<it->first;
    for(it++;it!=mp.end();it++)
            cout<<" "<<it->first;

    return 0;
}
