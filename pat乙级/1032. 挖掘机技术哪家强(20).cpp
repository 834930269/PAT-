#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    map<int,int> school;
    int N,maxsno=0,maxsum=0;
    cin>>N;
    while(N--){
        int sum,sno;
        cin>>sno>>sum;
        school[sno]+=sum;
        if(school[sno]>maxsum){
            maxsum=school[sno];
            maxsno=sno;
        }
    }
    cout<<maxsno<<" "<<maxsum<<endl;
    return 0;
}
