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
const int T = 1e3+2;
const int p[2] = {31,47};
const int m[2] = {1073807359,1332968193};
ll po[2][T], ha[2][T];
int ans[T];
string s;
int n;

void pre() {
    for(int j = 0; j < 2; j++) {
        po[j][0] = 1;
        for(int i = 1; i < n; i++) {
            po[j][i] = (po[j][i-1]*p[j])%m[j];
            ha[j][i] = (ha[j][i-1]+(s[i]-'a')*po[j][i])%m[j];
            ans[i] = 0;
        }
    }
}

ii fixBase(ii ok, int i) {
    ok.fi = (ok.fi * po[0][n-i])%m[0];
    ok.se = (ok.se * po[1][n-i])%m[1];
    return ok;
}

void solve() {
    for(int t = 1; t < n; t++) {
        for(int ini = 0; ini < t; ini++) {
            ii ok = mk((ha[0][ini+t]-ha[0][ini]+m[0])%m[0],
                       (ha[1][ini+t]-ha[1][ini]+m[1])%m[1]);
            ok = fixBase(ok,ini+1);
            int c = 1;
            ans[c] = max(ans[c],c*t);
            for(int k = ini+t*2; k < n; k+=t) {
                ii nok = mk((ha[0][k]-ha[0][k-t]+m[0])%m[0],
                          (ha[1][k]-ha[1][k-t]+m[1])%m[1]);
                nok = fixBase(nok,k-t+1);
                if(ok==nok) c++;
                else c = 1;
                ans[c] = max(ans[c],c*t);
                swap(ok,nok);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        cin >> s;
        n = s.size()+1;
        s = "#"+s;
        pre();
        solve();
        cout << "Case #" << ++cont << ": " << n-1 << (2==n? '\n' : ' ');
        for(int i = 2; i < n; i++) {
            cout << ans[i] << (i+1==n? '\n' : ' ');
        }
    }
    return 0;
}

