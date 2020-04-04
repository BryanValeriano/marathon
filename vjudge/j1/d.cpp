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
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int N = 2e5 + 2;
const ll T = 1e15;

bool ok[N];
int pi[N];
vii t;
vii s;

bool equal(ii &a, ii &b, int k, int m) {
    if(k == 0 or k == m-1)
        return (a.fi <= b.fi and a.se == b.se);
    return a == b;
}

vii compress(vii &v) {
    memset(ok,0,sizeof ok);
    for(int i = 1; i < v.size(); i++) {
        if(v[i].se == v[i-1].se) {
            ok[i-1] = 1;
            v[i].fi += v[i-1].fi;
        }
    }

    vii tmp;
    for(int i = 0; i < v.size(); i++)
        if(!ok[i]) tmp.eb(v[i]);

    return tmp;
}

void pre() {
    s.eb(-1,-1);
    pi[0] = pi[1] = 0;
    for(int i = 2; i <= s.size(); i++) {
        pi[i] = pi[i-1];
        while(pi[i] > 0 and s[pi[i]] != s[i-1]) pi[i] = pi[pi[i]];
        if(s[pi[i]] == s[i-1]) pi[i]++;
    }
}

int kmp() {
    pre();
    int k = 0, ans = 0;
    int m = s.size()-1;
    for(int i = 0; i < t.size(); i++) {
        while(k > 0 and !equal(s[k],t[i],k,m)) k = pi[k];
        if(equal(s[k],t[i],k,m)) k++;
        if(k >= m) {
            ans++;
            if(s[k-1] != t[i]) {
                k--;
                while(k > 0 and !equal(s[k],t[i],-1,m)) k = pi[k];
                if(equal(s[k],t[i],k,m)) k++;
            }
        }
    }
    return ans;
}

ll kmp2() {
    ll ans = 0;
    for(int i = 0; i < t.size(); i++)
        if(s[0].se == t[i].se) ans += max(0ll,(t[i].fi-s[0].fi+1));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int x; char a,b;
        cin >> x >> a >> b;
        t.eb(x,T+(b-'a'));
    }
    t = compress(t);

    for(int i = 0; i < m; i++) {
        int x; char a,b;
        cin >> x >> a >> b;
        s.eb(x,T+(b-'a'));
    }
    s = compress(s);

    if(s.size() == 1) cout << kmp2() << endl;
    else cout << kmp() << endl;

    return 0;
}

