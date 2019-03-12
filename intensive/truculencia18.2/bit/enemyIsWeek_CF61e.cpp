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
int bit[T];
int n;

void update(int pos) {
    for(; pos < T; pos += (pos & -pos)) bit[pos] += val;
}

int query(int pos) {
    int ans = 0;
    for(; pos > 0; pos -= (pos & -pos)) ans += bit[pos];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    vector<int>v;
    vector<int>ve;
    map<int,int> id;
    int x;
    cin >> n;

    for(int i = 0; i < n; i++) { cin >> x; v.pb(x); ve.pb(x); }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) id[v[i]] = i+1;
    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll tmp = query(T-1) - query(id[ve[i]]);
        update(id[ve[i]]);
    }
    cout << ans << endl;
    return 0;
}

