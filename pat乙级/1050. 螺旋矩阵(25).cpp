#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main(){
    ios::sync_with_stdio(false);
    int N,matrix[10001],mine=9999,r,c,tot,x,y;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>matrix[i];
    }
    sort(matrix,matrix+N,cmp);
    for(int i=1;i<=sqrt(N*1.0);++i)
        if(N%i==0)//N/iΪm,mΪ����
            if(N/i-i<mine){
                mine=N/i-i;//��¼m-n����Сֵ
                r=i;//��¼��Сֵ��n,nΪ��,����row
            }
    c=N/r;//colum
    int a[c][r];
    memset(a,0,(r*c)*sizeof(int));
    a[0][0]=matrix[0];
    tot=x=y=0;
    while(tot<r*c-1){//һ�δ���һȦ,
        while(y+1<r && !a[x][y+1])//ÿ��ѭ�������һ��
            a[x][++y]=matrix[++tot];
        while(x+1<c && !a[x+1][y])//�ұߵ�һ��,�ϵ���
            a[++x][y]=matrix[++tot];
        while(y-1>=0 && !a[x][y-1])//�����һ��,���ҵ���
            a[x][--y]=matrix[++tot];
        while(x-1>=0 && !a[x-1][y])//��ߵ�һ��,���µ���
                                                           //һȦ������,��һȫ�ĳ�ʼx,y������������ѭ������
            a[--x][y]=matrix[++tot];
    }
    for(int i=0;i<c;++i){
        cout<<a[i][0];
        for(int j=1;j<r;++j)
            cout<<" "<<a[i][j];
        cout<<endl;
    }
    return 0;
}
