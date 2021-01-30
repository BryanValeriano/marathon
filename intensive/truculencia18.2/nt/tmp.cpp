#include<bits/stdc++.h>
using namespace std;
#define N 40000000
int a[N+5],u[N+5],prime[N+5],s[N+5];

int main() {
	int n,i,j,g,x,ans=0;
    int sz = 0;
	//for(i=2;i<=MX;++i) {
	//	if(!u[i]) u[i] = p[++pn] = i, sz++;
	//	for(j=1;i*p[j]<=MX;++j){
    //        u[i*p[j]]=p[j];
    //        if(i%p[j]==0) break;
    //    }
    //}
    for(int i=2;i< N;++i) {
        if(!u[i]) u[i] = prime[sz++] = i;
        for(int j=0;i*prime[j] < N ; ++j){
            u[i*prime[j]]=prime[j];
            if(i%prime[j]==0) break;
        }
    }


    cout << sz << endl;
    for(int i = 0; i < sz; i++) cout << prime[i] << endl;
}
