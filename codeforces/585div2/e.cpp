#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const ll INF = 0x3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);

const int N = 21;
const int T = (1 << 21);
vector<int> v[N];
ll troc[N][N];
ll dp[T];
int n, gol;

ll solve(int mask) {
    if(mask == gol) return 0;
    if(dp[mask] != INF) return dp[mask];

    for(int i = 1; i <= 20; i++) {
        if(!v[i].size()) continue;
        if(mask & (1 << i)) continue;
        ll sum = 0;
        for(int j = 1; j <= 20; j++) {
            if(! (mask & (1 << j)) or i == j) continue;
            sum += troc[j][i];
        }
        dp[mask] = min(dp[mask], solve(mask | (1 << i)) + sum);
    }

    return dp[mask];
}

int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < T; i++) dp[i] = INF;
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v[x].pb(i);
        gol |= (1 << x);
    }

    for(int i = 1; i <= 20; i++) {
        for(int j = 1; j <= 20; j++) {
            if(i == j or (!v[i].size()) or (!v[j].size())) continue;
            int r = 0, l = 0;
            while(r < v[i].size()) {
                while(l < v[j].size() and v[i][r] > v[j][l]) l++;
                troc[i][j] += (ll)l;
                r++;
            }
        }
    }

    cout << solve(0) << endl;
    return 0;
}
