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
        if(N%i==0)//N/i为m,m为整数
            if(N/i-i<mine){
                mine=N/i-i;//记录m-n的最小值
                r=i;//记录最小值的n,n为行,赋给row
            }
    c=N/r;//colum
    int a[c][r];
    memset(a,0,(r*c)*sizeof(int));
    a[0][0]=matrix[0];
    tot=x=y=0;
    while(tot<r*c-1){//一次处理一圈,
        while(y+1<r && !a[x][y+1])//每次循环处理第一行
            a[x][++y]=matrix[++tot];
        while(x+1<c && !a[x+1][y])//右边第一列,上到下
            a[++x][y]=matrix[++tot];
        while(y-1>=0 && !a[x][y-1])//下面第一行,从右到左
            a[x][--y]=matrix[++tot];
        while(x-1>=0 && !a[x-1][y])//左边第一列,从下到上
                                                           //一圈处理完,下一全的初始x,y由下面这两个循环决定
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
