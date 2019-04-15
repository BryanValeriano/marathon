#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
typedef tuple<int,int,int> iii;
const int INF = 0x3f3f3f3f;

const int T = 4e5 + 10;
vector<int> v;
unordered_map<int,int> id;
vector<iii> q;
int ans[T];
int bit[T];

void update(int x) {
    for(int i = x; i < T; i += i&-i) bit[i] += 1;
}

int query(int x) {
    int ans = 0;
    for(int i = x; i > 0; i -= i&-i) ans += bit[i];
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,a,b; cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        q.eb(a,b,i);
        v.pb(a);
        v.pb(b);
    }
    
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for(int i = 0; i < v.size(); i++) id[v[i]] = i+1;

    sort(q.begin(), q.end(), [] (const iii &a, const iii &b) { return get<1>(a) < get<1>(b); });

    for(int i = 0; i < n; i++) {
        ans[get<2>(q[i])] = query(T-1) - query(id[get<0>(q[i])]);
        update(id[get<0>(q[i])]);
    }

    for(int i = 0; i < n; i++) cout << ans[i] << endl;

    return 0;
}

