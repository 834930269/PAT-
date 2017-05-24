#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){//插入:前面必定有序
                   //按插如来判断
    int N,A1[101],A2[101],i=0,j=0;
    cin>>N;

    for(i=0;i<N;i++) cin>>A1[i];
    for(i=0;i<N;i++) cin>>A2[i];

    for(i=0;A2[i]<=A2[i+1]&&i<N;i++); //找到第一个破坏排序的下标
    for(j=++i;A1[j]==A2[j]&&j<N;j++);  //插入排序后面的必定相同,若存在不同,则改判为归并

    if(j==N){
        cout<<"Insertion Sort"<<endl;
        sort(A1,A1+i+1);
    }else{
        cout<<"Merge Sort"<<endl;
        int k=1;
        int flag=1;//用来标记是否归并排序到序列等于"中间序列"
        while(flag)
        {
            flag=0;
            for(i=0;i<N;i++){
                if(A1[i]!=A2[i])
                    flag=1;
            }
            k*=2;
            for(i=0;i<N/k;i++)//一次归并迭代次数
                sort(A1+i*k,A1+(i+1)*k);
            if(k*(N/k)<N) // 对 非偶数序列的“尾巴”进行排序
                sort(A1+k*(N/k),A1+N);
        }
    }
    cout<<A1[0];
    for(i=1;i<N;i++)
        cout<<" "<<A1[i];
    cout<<endl;
    return 0;
}
