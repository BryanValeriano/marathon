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
const int T = 1e5+10;
const int p[2]= {31,47};
const int m[2] = {1073807359,1442968193};
ll po[2][T], ha[2][T];
set<ii> bag;
int n,k;
string s;

ii fixBase(ii ok, int i) {
    ok.fi = (ok.fi * po[0][n-i]) % m[0];
    ok.se = (ok.se * po[1][n-i]) % m[1];
    return ok;
}

void pre() {
    for(int j = 0; j < 2; j++) {
        po[j][0] = 1;
        for(int i = 1; i < n; i++) {
            po[j][i] = (po[j][i-1] * p[j])%m[j];
            ha[j][i] = (ha[j][i-1] + (s[i]-'a'+1)*po[j][i])%m[j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> k >> s;
        s = "#" + s;
        n++;
        pre();
        for(int i = k; i < n; i++) {
            ii ok = mk((ha[0][i]-ha[0][i-k]+m[0])%m[0],
                       (ha[1][i]-ha[1][i-k]+m[1])%m[1]);
            ok = fixBase(ok,i);
            bag.insert(ok);
        }
        cout << bag.size() << endl;
        bag.clear();
    }
    return 0;
}

