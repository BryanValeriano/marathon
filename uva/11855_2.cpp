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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 2e3;

const ll p[2] = {31,47};
const ll m[2] = {1000000009,1073807359};
ll po[2][T], ha[2][T];
unordered_map<int,int> id[T];
int ans[T];

void pre() {
    for(int j = 0; j < 1; j++) {
        po[j][0] = 1;
        for(int i = 1; i < T; i++)
            po[j][i] = (po[j][i-1]*p[j])%m[j];
    }
}

string junta(string s) {
    string t;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') continue;
        t += s[i];
    }
    return t;
}

int fixBase(int ok, int i) {
    ok = (ok*po[0][T-i])%m[0];
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s;
    pre();
    int c = 0;
    while(getline(cin,s)) {
        if(c) cout << endl;
        s = junta(s);
        s = "#"+s;
        for(int i = 1; i < s.size(); i++) {
            id[i].clear();
            ans[i] = 0;
            for(int j = 0; j < 1; j++)
                ha[j][i] = (ha[j][i-1] + (s[i]-'A'+1)*po[j][i])%m[j];
        }
        for(int i = 1; i < s.size(); i++) {
            for(int j = i; j < s.size(); j++) {
                int ok = (ha[0][j]-ha[0][i-1]+m[0])%m[0];
                ok = fixBase(ok,i);
                id[j-i+1][ok]++;
                int x = id[j-i+1][ok];
                if(ans[j-i+1] < x) ans[j-i+1] = x;
            }
        }
        for(int i = 1; i < s.size(); i++)
            if(ans[i] > 1) cout << ans[i] << endl;
        c++;
    }
    return 0;
}

