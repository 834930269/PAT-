#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int N,M;

struct DisjointSet{
    vector<int> father,rank,friends;
    int maxfriend;
    DisjointSet(int n):father(n+1),rank(n+1),friends(n+1){
        for(int i=1;i<=n;++i){
            father[i]=i;
            friends[i]=1;
        }
        maxfriend=1;
    }

    int find(int t){
        return father[t]=father[t]==t?t:find(father[t]);
    }

    void merge(int x,int y){
        int a=find(x),b=find(y);

        if(rank[a]<rank[b]){
            father[a]=b;
            if(a!=b){
                friends[b]+=friends[a];
                friends[a]=friends[b];
            }
        }else{
            father[b]=a;
            if(a!=b){
                friends[b]+=friends[a];
                friends[a]=friends[b];
            }
            if(rank[a]==rank[b]){
                rank[a]++;
            }
        }
        maxfriend=max(maxfriend,friends[b]);
    }
};

int main(){
    while(~scanf("%d%d",&N,&M)){
        DisjointSet djs(N);
        int k,ind;
        for(int i=0;i<M;++i){
            scanf("%d",&k);
            scanf("%d",&ind);
            k--;
            int q;
            for(int j=0;j<k;++j){
                scanf("%d",&q);
                djs.merge(ind,q);
            }
        }
        printf("%d\n",djs.maxfriend);
    }
    return 0;
}
