#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a,int b){
  return a>b;                           //��������Ϊa<b�������Ϊreturn a>b����Ϊ����
}

int main(){
    ios::sync_with_stdio(false);
    int N,dis[100001]={0},j=0;
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>dis[i];
    sort(dis+1,dis+N+1,compare);
    for(j=1;j<=N;j++)//�����1��,�����0�еĻ��ᵼ�¼�������,
        if(dis[j]<=j)break;
    cout<<j-1<<endl;
    return 0;
}
