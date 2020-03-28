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
const ll MOD = 1e9 + 7;
const int T = 1e5 + 2;

ll acum[5][T];

ll calc(ll x) {
    cout << x << endl;
    if(!x) return 0;
    return ((x*(x-1)<<1)+(x))%MOD;
}

int id(char x) {
    if(x == '?') return 3;
    return x - 'A';
}

int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s;

    for(int i = 0; i < s.size(); i++) acum[id(s[i])][i]++;

    for(int j = 0; j < 4; j++)
        for(int i = 1; i < s.size(); i++)
            acum[j][i] += acum[j][i-1];

    ll ans = 0;
    int n = s.size()-1;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'B' or s[i] == '?') {
            int wat = s[i] == '?';
            ll aBefore = (calc(acum[3][i]-wat)+acum[0][i])%MOD;
            ll cAfter = (calc(acum[3][n]-acum[3][i])+(acum[2][n]-acum[2][i]))%MOD;
            cout << aBefore << " " << cAfter << endl;
            ll more = (aBefore*cAfter)%MOD;
            ans = (ans+more)%MOD;
        }
    }

    cout << ans << endl;

    return 0;
}

