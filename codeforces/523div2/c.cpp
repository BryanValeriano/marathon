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
const int T = 1e6 + 10;
const int MOD = 1e9 + 7;
int memo[T];
vector<int> divs[T];

int main() {
    ios::sync_with_stdio(false);
    int v;
    int n; cin >> n;

    for(int i = 1; i <= T; i++)
        for(int j = i; j <= T; j += i)
            divs[j].pb(j/i);

    memo[0] = 1;

    for(int i = 1; i <= n; i++) {
        cin >> v;
        for(auto x : divs[v])
            memo[x] = (memo[x] + memo[x-1]) % MOD;
    }

    int ans = 0;

    for(int i = 1; i <= n; i++)
        ans = (ans + memo[i]) % MOD;
    cout << ans << endl;
    return 0;
}

