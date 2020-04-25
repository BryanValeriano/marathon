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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 5e5 + 4;
int bit[T];

void update(int pos) {
    for(; pos < T; pos += pos&(-pos)) bit[pos]++;
}

int rsq(int pos) {
    int sum = 0;
    for(;pos;pos-=pos&(-pos)) sum += bit[pos];
    return sum;
}

ll query(int pos) {
    return rsq(T-1) - rsq(pos);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    vector<int> v;
    vector<int> ve;
    map<int,int> id;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.pb(x);
        ve.pb(x);
    }

    sort(ve.begin(),ve.end());
    ve.resize(unique(ve.begin(),ve.end())-ve.begin());
    for(int i = 0; i < ve.size(); i++) id[ve[i]] = i+1;

    ll ans =0;
    for(auto x : v) {
        x = id[x];
        ans += query(x);
        update(x);
    }

    cout << ans << endl;

    return 0;
}

