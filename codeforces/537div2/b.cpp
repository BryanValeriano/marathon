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
long double v[T];

int main() {
    ios::sync_with_stdio(false);
    ll n, k, m;
    cin >> n >> k >> m;
    int aux;
    for(int i = 1; i <= n; i++) { cin >> aux; v[i] = aux; }
    sort(v, v+n+1);
    for(int i = 2; i <= n; i++) v[i] += v[i-1];
    long double best = (v[n] + min(m, (k * n)))/n;
    for(ll i = 1; i <= min(m,n-1); i++) 
        best = max(best, ((v[n] - v[i]) + min(m-i, k * (n-i)))/(n-i));
    cout << fixed << setprecision(6) << best << endl;
    return 0;
}

