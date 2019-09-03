#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef unsigned long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
const int T = 30;
const int TT = 1e6;
int n, m;
ll gol;
ll tests[T];
vector<ll> track;

ll getProbs() {
    int best = INF;
    ll ans = 0;
    for(auto x : track) {
        int count = __builtin_popcountll(x);
        if(best > count) {
            best = count;
            ans = x;
        }
    }
    return ans;
}

int solve(ll i, ll test, ll mask) {
    if(i == n && mask != gol) return INF;
    if(mask == gol) {
        track.pb(test);
        return 0;
    }

    int ans = INF;
    ans = solve(i+1, test | (1LL<<i), mask | tests[i]) + 1;
    ans = min(ans, solve(i+1, test, mask));

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        for(int j = 0; j < x; j++) {
            ll y; cin >> y;
            y--;
            tests[i] |= (1LL << y);
        }
    }
    for(ll i = 0; i < m; i++) gol |= (1LL<<i);
    cout << solve(0,0,0) << endl;
    ll x = getProbs();
    for(int i = 0; i < n; i++) if(x & (1<<i)) cout << i+1 << " ";
    cout << endl;
    return 0;
}

