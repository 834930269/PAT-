#include<iostream>
#include<algorithm>
#include<map>
#include<cstdio>
using namespace std;

typedef long long LL;

LL a[100001],b[100001];

int main(){//��Ϊ���ݹ��� �� ���� ǰ�� ˳���ƻ���Ԫ��,�������ƻ�����Ԫ�ض�������Ԫ.
                   //����Ϊ���ڲ�����Ϊ��Ԫ������,��֮������Ϊ��Ԫ������Ҳ��Ҫ������Щ��������
                   //���ԲŻ���b[i]>Max
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
