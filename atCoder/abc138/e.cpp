#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 3;
const int N = 27;
int v[T][N];
string s,t;

int main() {
    ios::sync_with_stdio(false);
    memset(v, INF, sizeof v);
    cin >> s >> t;
    int n = s.size();
    s = "#" + s;

    for(int i = 1; i <= n; i++) v[i-1][s[i]-'a'] = i;

    for(int i = 0; i < 27; i++)
        for(int j = n; j >= 0; j--)
            v[j][i] = min(v[j][i], v[j+1][i]);

    ll ans = 0;
    int at = 0;
    int as = 0;

    while(at < t.size()) {
        if(v[as][t[at]-'a'] == INF) {
            if(as == 0) { cout << -1 << endl; return 0; }
            as = 0;
            ans += n;
        } else {
            as = v[as][t[at]-'a'];
            at++;
        }
    }

    cout << ans + as << endl; 

    return 0;
}

