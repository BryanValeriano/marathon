#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int n,s;
    cin>>n;
    int m[n][n],l[n],c[n],d1,d2;
    d1=0;
    d2=0;
    s=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>m[i][j];
            l[i]=0;
            c[i]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            l[i]=m[i][j]+l[i];
            c[i]=m[j][i]+c[i];
        }
        d1=m[i][i]+d1;
        d2=m[i][(n-1)-i]+d2;
    }
    if(d1==d2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(l[i]!=l[j] || c[i]!=c[j]){
                    s=-1;
                }
            }
        }
        if(c[0]==l[0] && d1==c[0] && s != -1){
            s=d1;
        } else s = -1;
    }else{
        s=-1;
    }

    cout<<s;
}
