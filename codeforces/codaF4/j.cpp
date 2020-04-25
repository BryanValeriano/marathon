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

void update(int pos, vector<int> &bit) {
    for(; pos < bit.size(); pos += pos&(-pos)) bit[pos]++;
}

int query(int pos, const vector<int> &bit) {
    int ans = 0;
    for(;pos;pos-=pos&(-pos)) ans += bit[pos];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,k,q,op,x;
    cin >> n >> k >> q;
    vector<int> v(n);
    vector<bool> vis(n);
    vector<int> bit(n+5);
    map<int,int> id;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        id[v[i]] = 1;
    }

    int ok = 1;
    for(auto x : id) id[x.fi] = ++ok;

    while(q--) {
        cin >> op >> x;
        x--;
        if(op&1) update(id[v[x]],bit), vis[x] = 1;
        else cout << (query(ok,bit)-query(id[v[x]]-1,bit) <= k and vis[x]? "YES\n" : "NO\n");
    }

    return 0;
}

