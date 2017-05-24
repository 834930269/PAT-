#include<iostream>
#include<algorithm>
#include<map>
#include<cstdio>
using namespace std;

typedef long long LL;

LL a[100001],b[100001];

int main(){//因为根据规则 当 出现 前后 顺序被破坏的元素,则被他所破坏所有元素都不是主元.
                   //但因为存在不能做为主元的数据,而之后能作为主元的数据也需要大于那些垃圾数据
                   //所以才会有b[i]>Max
    ios::sync_with_stdio(false);
    int N,cnt=0,Max=0;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+N);
    Max=0;
    int v[100000];
    for(int i=0;i<N;i++){
        if(a[i]==b[i]&&b[i]>Max)
            v[cnt++]=b[i];
            if(b[i]>Max)
                Max=b[i];
    }
    cout<<cnt<<endl;
    if(cnt){
        cout<<v[0];

        for(int i=1;i<cnt;i++){
            cout<<" "<<v[i];
        }
    }
    cout<<endl;
    return 0;
}
