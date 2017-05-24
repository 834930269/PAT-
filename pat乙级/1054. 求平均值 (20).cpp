#include<algorithm>
#include<string>
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

inline bool check(char *db){
    int i=0;
    bool point=false;
    int cnt=0;
    if(db[i]=='-')
            i++;
    while(db[i]!='\0'){
        if((db[i]<'0' || db[i]>'9') && db[i]!='.') return false;
        if(point && db[i]=='.') return false;
        if(point) cnt++;
        if(db[i]=='.')point=true;
        i++;
    }
    if(cnt>2) return false;
    if(atof(db)>1000.0 || atof(db)<-1000.0)
        return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    int N,cnt=0;
    double sum=0.0f,v;
    cin>>N;
    while(N--){
        char db[100]={0};
        cin>>db;
        if(check(db)){
            sum+=atof(db);
            cnt++;
        }else{
            cout<<"ERROR: "<<db<<" is not a legal number"<<endl;
        }
    }
    v=sum/cnt;
    if(cnt==0)
        cout<<"The average of 0 numbers is Undefined"<<endl;
    else if(cnt==1){
        printf("The average of %d number is %.2lf\n",cnt,v);
    }else{
        printf("The average of %d numbers is %.2lf\n",cnt,v);
    }
    return 0;
}
