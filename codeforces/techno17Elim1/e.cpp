#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e6+5;
const int p[2] = {31,47};
const int m[2] = {1073807359,1332968193};
ll po[2][T+12], ha[2][T+12];
map<ii,int> id;
map<ii,int> vis;
int cont,vez;

void pre() {
    for(int j = 0; j < 2; j++) {
        po[j][0] = 1;
        for(int i = 1; i <= T; i++) {
            po[j][i] = (po[j][i-1]*p[j])%m[j];
        }
    }
}

ii rollH(string s) {
    int n = s.size();
    for(int j = 0; j < 2; j++)
        for(int i = 1; i < n; i++)
            ha[j][i] = (ha[j][i-1] + (s[i]-'a'+1)*po[j][i])%m[j];
    return mk(ha[0][n-1],ha[1][n-1]);
}

ii fixBase(ii ok, int i) {
    ok.fi = (ok.fi*po[0][T-i])%m[0];
    ok.se = (ok.se*po[1][T-i])%m[1];
    return ok;
}

void add(string s) {
    ii ok = rollH(s);
    ok = fixBase(ok,1);
    id[ok] = ++cont;
}

vi solve(int start, int k, int n) {
    vi ans;
    ++vez;
    for(int i = start+k; i < n; i += k) {
        ii ok = mk((ha[0][i]-ha[0][i-k]+m[0])%m[0],
                   (ha[1][i]-ha[1][i-k]+m[1])%m[1]);
        ok = fixBase(ok,i-k+1);
        if(!id.count(ok)) return ans;
        if(vis[ok] == vez) return ans;
        vis[ok] = vez;
        ans.pb(id[ok]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    pre();
    int b,k;
    cin >> b >> k;
    string s; cin >> s;
    string t;

    for(int i = b*k-k+1; i < b*k; i++) t += s[i];
    s = "#"+t+s;
    int q; cin >> q;

    while(q--) {
        cin >> t;
        t = "#"+t;
        add(t);
    }

    rollH(s);
    int n = s.size();
    //cout << s << endl;

    for(int i = 0; i < k; i++) {
        vi ans = solve(i,k,n);
        if(ans.size() == b) {
            cout <<"YES\n";
            for(int x : ans) cout << x << " ";
            cout << endl;
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}

