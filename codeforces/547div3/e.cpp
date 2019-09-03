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
const ll INF = 0x3f3f3f3f3f3f3f;

const int T = 1e6;
ll v[T];

int main() {
    ios::sync_with_stdio(false);
    ll h, n;
    ll tot = 0;
    cin >> h >> n;
    ll tmp = h;
    ll mini = INF;
    for(int i = 1; i <= n; i++) {
        cin >> v[i], tot += v[i];
        mini = min(mini, tot);
        tmp += v[i];
        if(tmp <= 0) { cout << i << endl; return 0; }
    }
    for(int i = n+1; i <= 2*n; i++) v[i] = v[i-n];
    if(tot >= 0) { cout << -1 << endl; return 0; }
    ll vezes = (h + mini)/abs(tot);
    vezes = max(0LL, vezes);
    h += (vezes * tot); 
    ll ans = vezes * n;
    for(int i = 1; i <= 2*n; i++) {
        h += v[i];
        ans++;
        if(h <= 0) { cout << ans << endl; return 0; }
    }
    cout << -1 << endl;
    return 0;
}

