#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int N,drunk[2]={0};
    cin>>N;
    while(N--){
        int a,A,b,B;
        cin>>a>>A>>b>>B;
        if(A==B)
            continue;
        if(A==(a+b))
            drunk[0]++;
        if(B==(a+b))
            drunk[1]++;
    }
    cout<<drunk[1]<<" "<<drunk[0]<<endl;
    return 0;
}
