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
const int T = 1e5 + 4;
const ll N = 40;
const int K = T*N;

ll v[T];
ll ve[T][N];
int trie[K][2];
int n, nodes, root;

ll pre(int r, int l) {
    ll ans = 0;
    for(ll j=1,casa=0; casa < N; j <<=1,casa++)
        if((ve[r][casa]-ve[l][casa])&1) ans += j;

    return ans;
}

vector<bool> getBits(ll x) {
    vector<bool> tmp;
    for(ll j=1,casa=0; casa < N; j <<=1,casa++)
        tmp.pb(x&j?1:0);
    return tmp;
}

void insert(ll x) {
    vector<bool> bits = getBits(x);
    int node = root;
    while(bits.size()) {
        bool at = bits.back();
        bits.pop_back();
        if(!trie[node][at]) trie[node][at] = ++nodes;
        node = trie[node][at];
    }
    if(nodes >= K) cout << "olha la " << nodes << endl;
}

ll query(ll x) {
    vector<bool> bits = getBits(x);
    int node = root;
    ll ans = 0;
    ll val = (1ll << (N-1));
    while(bits.size()) {
        bool at = bits.back();
        bits.pop_back();
        if(trie[node][!at]) {
            ans += val;
            node = trie[node][!at];
        } else node = trie[node][at];
        val >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        for(ll j=1,casa=0; casa < N; j <<=1,casa++) {
            if(v[i]&j) ve[i][casa]++;
            ve[i][casa] += ve[i-1][casa];
        }
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        insert(pre(i-1,0));
        ans = max(ans,query(pre(n,i-1)));
    }

    insert(pre(n,0));
    ans = max(ans,query(0));

    cout << ans << endl;

    return 0;
}
