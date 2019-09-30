#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const ll INF = 0x3f3f3f3f3f3fef;

const int V = 1e5+2;
const int N = 102;

ll dp[V];
ll p[N];
ll v[N];
ll n,w;
 
int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < V; i++) dp[i] = INF;

    cin >> n >> w;
    for(int i = 0; i < n; i++) cin >> p[i] >> v[i];
    
    dp[0] = 0;

    for(int i = 0; i < n; i++) 
        for(ll j = V-1; j-v[i] >= 0; j--)
            dp[j] = min(dp[j], dp[j-v[i]]+p[i]);

    for(int i = V-1; i >= 0; i--)
        if(dp[i] <= w) { cout << i << endl; return 0; }


    return 0;
}

