#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main(){//����:ǰ��ض�����
                   //���������ж�
    int N,A1[101],A2[101],i=0,j=0;
    cin>>N;

    for(i=0;i<N;i++) cin>>A1[i];
    for(i=0;i<N;i++) cin>>A2[i];

    for(i=0;A2[i]<=A2[i+1]&&i<N;i++); //�ҵ���һ���ƻ�������±�
    for(j=++i;A1[j]==A2[j]&&j<N;j++);  //�����������ıض���ͬ,�����ڲ�ͬ,�����Ϊ�鲢

    if(j==N){
        cout<<"Insertion Sort"<<endl;
        sort(A1,A1+i+1);
    }else{
        cout<<"Merge Sort"<<endl;
        int k=1;
        int flag=1;//��������Ƿ�鲢�������е���"�м�����"
        while(flag)
        {
            flag=0;
            for(i=0;i<N;i++){
                if(A1[i]!=A2[i])
                    flag=1;
            }
            k*=2;
            for(i=0;i<N/k;i++)//һ�ι鲢��������
                sort(A1+i*k,A1+(i+1)*k);
            if(k*(N/k)<N) // �� ��ż�����еġ�β�͡���������
                sort(A1+k*(N/k),A1+N);
        }
    }
    cout<<A1[0];
    for(i=1;i<N;i++)
        cout<<" "<<A1[i];
    cout<<endl;
    return 0;
}
