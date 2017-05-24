#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;

const char mp[14]={'0','1','2','3','4','5','6','7','8','9','J','Q','K'};

int main(){
    string T,Q;
    cin>>T>>Q;
    char AD[100];
    bool Mac=false,ADD=false;
    for(int i=Q.size()-1,p=T.size()-1;p>=0;i--,p--){
        if(i<0){
            if(!Mac){
                AD[p]=mp[(T[p]-'0')%13];
                Mac=true;
            }else{
                AD[p]=mp['0'-T[p]==0?0:'0'-T[p]+10];
                Mac=false;
            }
            ADD=true;
        }else{
            if(!Mac){
                Q[i]=mp[(Q[i]-'0'+T[p]-'0')%13];
                Mac=true;
            }else{
                Q[i]=mp[Q[i]-T[p]>=0?Q[i]-T[p]:Q[i]-T[p]+10];
                Mac=false;
            }
        }
    }
    if(ADD)
        cout<<AD<<Q<<endl;
    else
        cout<<Q<<endl;
    return 0;
}
