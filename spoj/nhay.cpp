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
const int T = 1e6+2;
const int p[3] = {31,47,53};
const ll m[3] = {1000000009,1073807359,1442968193};
ll po[3][T], inv[3][T], ha[3][T];
int k;

ll ele(ll b, ll e, ll mod) {
    ll ans = 1;
    while(e) {
        if(e&1) ans = ans*b%mod;
        b = b*b%mod;
        e >>= 1;
    }
    return ans;
}

void pre(string s) {
    int n = s.size();

    for(int j = 0; j < 3; j++) {
        po[j][0] = 1;
        inv[j][0] = ele(po[j][0],m[j]-2,m[j]);
        for(int i = 1; i < n; i++) {
            po[j][i] = (po[j][i-1]*p[j]) % m[j];
            //inv[j][i] = ele(po[j][i],m[j]-2,m[j]);
        }
        for(int i = 1; i < n; i++) {
            ha[j][i] = (ha[j][i-1] + (s[i]-'a'+1)*po[j][i]) % m[j];
        }
    }
}

int hsh(int l, int r, int c) {
    ll tmp = (ha[c][r]-ha[c][l-1] + m[c]) % m[c];
    //tmp = (tmp * inv[c][l-1]) % m[c];
    return tmp;
}

int main() {
    ios_base::sync_with_stdio(false);
    int c = 0;
    while(cin >> k) {
        if(c) cout << endl;
        string s,t;
        cin >> s >> t;
        t = "#"+t;
        s = "#"+s;
        int k = s.size();
        int n = t.size();
        pre(s);
        ii ok = mk(hsh(1,k-1,0),hsh(1,k-1,1));
        pre(t);
        for(int i = k-1; i < n; i++) {
            if(ok == mk(hsh(i-k+2,i,0),hsh(i-k+2,i,1))) {
                cout << i-k+1 << endl;
            }
            ok.fi = (ok.fi*po[0][1]) % m[0];
            ok.se = (ok.se*po[1][1]) % m[1];
        }
        c++;
    }
    return 0;
}
