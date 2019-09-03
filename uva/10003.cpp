#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 52;
ll v[T];
ll dp[T][T];
int vis[T][T];
int tam,n,vez;

ll solve(int l, int r) {
    if(vis[l][r] == vez) return dp[l][r];
    if(r - l <= 1) return 0;

    ll ans = INF;

    for(int i = l+1; i < r; i++) ans = min(ans, solve(l,i) + (v[r] - v[l]) + solve(i,r));
    vis[l][r] = vez;
    return dp[l][r] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> tam;
    while(tam) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> v[i];
        v[0] = 0;
        v[n+1] = tam;
        vez++;
        cout << "The minimum cutting is " << solve(0,n+1) << "." << endl;
        cin >> tam;
    }
    return 0;
}

