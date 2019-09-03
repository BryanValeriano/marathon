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

const int T = 110;
ii mapa[T];
int v[T];

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++) v[i] = s[i]- 'a' + 1;
    for(int i = 1; i <= 26 ; i++) mapa[i] = ii(i,i+26);
    int last = 1;
    int ans = 0;

    for(int i = 0; i < s.size(); i++) { 
        ans += min({abs(mapa[last].fi - mapa[v[i]].fi), abs(mapa[last].fi - mapa[v[i]].se),
                abs(mapa[last].se - mapa[v[i]].se), abs(mapa[last].se - mapa[v[i]].fi)});
        last = v[i];
    }
    cout << ans << endl;
    return 0;
}

