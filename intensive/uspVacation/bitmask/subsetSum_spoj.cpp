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
ll n, a, b;
ll v[T];
ll v2[T];
ll ans = 0;
set<ll> bit;
vector<ll> sums[2];

void merge() {
    sums[0].pb(0);
    sums[1].pb(0);
    sort(sums[0].begin(), sums[0].end());
    sort(sums[1].begin(), sums[1].end());
    for(auto x : sums[0]) { 
        ll aMais = a - x;
        ll falta = b - x;
        ll lower = lower_bound(sums[1].begin(), sums[1].end(), aMais) - sums[1].begin();
        ll upper = upper_bound(sums[1].begin(), sums[1].end(), falta) - sums[1].begin();
        ans += upper - lower;
        //cout << x << " " << aMais << " " << falta << " " << ans << endl;
        //cout << "DBG: " << lower << " " << upper << endl;
    }
}

void brute(int i, ll sum, ll mask, int vez) {
    if(mask != 0 and bit.count(mask)) return;
    bit.insert(mask);
    if(sum != 0) sums[vez].pb(sum);
    if((i == n/2 and vez == 0) or (i == n and vez == 1)) return;
    brute(i+1, sum + v[i], mask | (1<<i), vez);
    brute(i+1, sum, mask, vez);
}

void read() {
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++)
        cin >> v[i];
} 

int main() {
    ios::sync_with_stdio(false);
    read();
    brute(0,0,0,0);
    brute(n/2,0,0,1);
    merge();
    //cout << ans << endl;
    //for(auto x : sums[0]) cout << x << " ";
    //cout << endl;
    //for(auto x : sums[1]) cout << x << " ";
    //cout << endl;
    cout << ans << endl;
    return 0;
}

