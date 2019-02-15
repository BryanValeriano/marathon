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
const int T = 40;
const int N = 1e6;
ll n, a, b;
vector<ll> v[2];
ll ans = 0;
bool dp[N];
vector<ll> sums[2];
 
void merge() {
    sort(sums[0].begin(), sums[0].end());
    sort(sums[1].begin(), sums[1].end());
    for(auto x : sums[0]) { 
        ll aMais = a - x;
        ll falta = b - x;
        ll lower = lower_bound(sums[1].begin(), sums[1].end(), aMais) - sums[1].begin();
        ll upper = upper_bound(sums[1].begin(), sums[1].end(), falta) - sums[1].begin();
        if(lower < sums[1].size()) ans += (upper - lower);
    }
}
 
void brute(int i, ll sum, ll mask, int vez) {
	if(!dp[mask]) sums[vez].pb(sum); 
	dp[mask] = true;
	if(i == v[vez].size()) return;
 
    brute(i+1, sum + v[vez][i], mask | (1<<i), vez);
    brute(i+1, sum, mask, vez);
}
 
void read() {
    cin >> n >> a >> b;
	ll aux;
    for(int i = 0; i <= n/2; i++) {
		cin >> aux;
		v[0].pb(aux);
	}
	for(int i = n/2 + 1; i < n; i++) {
		cin >> aux;
		v[1].pb(aux);
	}
} 
 
int main() {
    ios::sync_with_stdio(false);
    read();
    brute(0,0,0,0);
	memset(dp, false, sizeof dp);
    brute(0,0,0,1);
    merge(); 
	cout << ans << endl;
    return 0;
}
