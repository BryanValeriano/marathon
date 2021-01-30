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
const ll p[2] = {31,47};
const ll m[2] = {1073807359,1442978193};
ll po[2][T], ha[2][T];

void pre(string s) {
    int n = s.size();
    for(int j = 0; j < 2; j ++) {
        po[j][0] = 1;
        for(int i = 1; i < n; i++) {
            po[j][i] = (po[j][i-1]*p[j])%m[j];
            ha[j][i] = (ha[j][i-1] + (s[i]-'a'+1)*po[j][i])%m[j];
        }
    }
}

bool check(int x, int n) {
    ii ok = mk(ha[0][x],ha[1][x]);
    for(int i = x+1; i < n-1; i++) {
        ok.fi = (ok.fi * po[0][1]) % m[0];
        ok.se = (ok.se * po[1][1]) % m[1];
        ii nok = mk((ha[0][i]-ha[0][i-x]+m[0])%m[0],
                    (ha[1][i]-ha[1][i-x]+m[1])%m[1]);
        if(ok == nok) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    s = "#"+s;
    pre(s);
    int n = s.size();
    int ans = -1;
    for(int i = n-2; i >= 1 and ans == -1; i--) {
        ii pre = mk((ha[0][i]*po[0][n-i-1])%m[0],
                    (ha[1][i]*po[1][n-i-1])%m[1]);
        ii suf = mk((ha[0][n-1]-ha[0][n-i-1]+m[0])%m[0],
                    (ha[1][n-1]-ha[1][n-i-1]+m[1])%m[1]);
        if(pre == suf and check(i,n)) ans = i;
    }
    cout << (ans==-1? "Just a legend" : s.substr(1,ans)) << endl;
    return 0;
}

