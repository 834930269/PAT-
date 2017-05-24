#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
int main(){
    int N,Tryno,Exmno,Try[1001]={0},print[1001];
    string sno;
    map<int,string> mp;
    cin>>N;
    while(N--){
        cin>>sno>>Tryno>>Exmno;
        mp[Tryno]=sno;
        Try[Tryno]=Exmno;
    }
    cin>>N;
    int i=0;
    while(N--)
        cin>>print[i++];

    for(int j=0;j<i;++j)
        cout<<mp[print[j]]<<" "<<Try[print[j]]<<endl;
    return 0;
}
