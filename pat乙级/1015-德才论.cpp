#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>
using namespace std;
typedef struct student{
    int num;
    int d;
    int c;

    bool operator<(const student &A)const{//依赖小于号,小于为真,当某类考生中有多人总分相同时，按其德
                                                                               //分降序排列；若德分也并列，则按准考证号的升序输出。
        if(d+c!=A.d+A.c)
            return d+c>A.d+A.c;
        else if(d!=A.d)
            return d>A.d;
        else return num<A.num;
    }
}student;

int main(){
        vector<student> A,B,C,D;//A，德才全尽,B德胜才C才德兼亡,D,其他
        int N,L,H,cnt=0;
        student tp;
        scanf("%d%d%d",&N,&L,&H);
       for(int i=0;i<N;i++){
            scanf("%d%d%d",&tp.num,&tp.d,&tp.c);
            if(tp.c>=L&&tp.d>=L){
                if(tp.d>=H&&tp.c>=H)
                    A.push_back(tp);
                else if(tp.d>=H)
                    B.push_back(tp);
                else if(tp.d>=tp.c)//有=
                    C.push_back(tp);
                else D.push_back(tp);
                    cnt++;
            }
       }

        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        sort(C.begin(),C.end());
        sort(D.begin(),D.end());
        vector<student>::iterator itr;
                printf("%d\n",cnt);
        for(itr=A.begin();itr!=A.end();++itr)
            printf("%d %d %d\n",itr->num,itr->d,itr->c);
        for(itr=B.begin();itr!=B.end();++itr)
            printf("%d %d %d\n",itr->num,itr->d,itr->c);
        for(itr=C.begin();itr!=C.end();++itr)
            printf("%d %d %d\n",itr->num,itr->d,itr->c);
        for(itr=D.begin();itr!=D.end();++itr)
            printf("%d %d %d\n",itr->num,itr->d,itr->c);
    return 0;
}
