#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define MAXN 1000100

typedef long long ll;
 
ll dp[MAXN + 5];
int cnts[MAXN + 5];
int n, k, m;

ll fever(int x) 
{
    if(dp[x] != 0) return dp[x];

    for(int i = 0; i < n; i++)
        dp[x] += (cnts[i]*fever(x - (i+1)) % m);

    return dp[x];
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n >> k >> m;

    for(int i = 0; i < n; i++) cin >> cnts[i];
    
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) cin >> dp[i];
    
    cout << fever(k-1) % m << endl;
    
    return 0;
}

