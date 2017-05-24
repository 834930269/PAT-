#include<iostream>
#include<algorithm>
using namespace std;
int main(){//感觉有dp的思想,但这里貌似是遍历
    long long N,p,cnt=0;
    cin>>N>>p;
    long long A[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A,A+N);
    int i;
    for(int j=0;j<N;j++)
        for(i=j+cnt;i<N;i++){
            if(A[i]>A[j]*p)
                break;
            cnt++;
        }
    cout<<cnt<<endl;
    return 0;
}
