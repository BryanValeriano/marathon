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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5+5;
ll suf[T];
ll v[T];

int main() {
    ios_base::sync_with_stdio(false);
    ll n,m; cin >> n >> m;
    ll sum = 0;
    ll need = INF;
    for(ll i = 0; i < m; i++) {
        cin >> v[i];
        sum += (ll)v[i];
        if(i+v[i] > n) {
            cout << -1 << endl;
            return 0;
        }
        need = n-(i+v[i]);
    }
    if(sum < n) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = m-1; i >= 0; i--)
        suf[i] += (v[i]+suf[i+1]);
    for(ll i = 0; i < m; i++)
        cout << max(i+1,n-suf[i]+1) << " ";
    cout << endl;
    return 0;
}

