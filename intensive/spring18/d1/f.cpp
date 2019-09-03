#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second


typedef long long int ll;

const int INF = 0x3f3f3f3f;

int n;
int vis = 0;
int v[5050];
int visit[5050][5050];
int memo[5050][5050];

inline int pd(int l, int r){

	if(l>=r)	return 0;

	int &pdm = memo[l][r];
	if(visit[l][r] == vis)	return pdm;
    
    int m = 0;
        
	if(v[l]==v[r])
		m = 1 + pd(l+1,r-1);
		
	pdm = max(m, max(pd(l+1,r),pd(l,r-1)));
    visit[l][r] = vis;
    return pdm;

}


void solve() {
	for(int i = 1; i <= n; i++)
        scanf("%d ", &v[i]);
    printf("%d\n", pd(1,n));
}

int main(){
	while(scanf("%d\n",&n) == 1 ) { ++vis; solve(); }

}
