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
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 10;

int n, k;
int dp[T][22];

bool solve(ll prod, int at) {
    if(at == k and prod == n) return 1;
    if(at == k) return 0;
    if(dp[prod][at] != -1) return dp[prod][at];

    for(ll i = 2; prod*i <= n; i++)
        if(solve(prod*i, at+1)) { cout << i << " ";  return 1; }

    return dp[prod][at] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    if(!solve(1, 0)) cout << -1;
    cout << endl;
    return 0;
}

