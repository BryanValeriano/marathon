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
const int T = 2e5 + 10;
int v[T];
bool tira[T];
int n, p;
string s;

bool cmp(ii &a, ii &b) {
    if(a.fi != b.fi) return a.fi > b.fi;
    return false;
}

void choose(int a, int b) {
    vii ve;
    for(int i = a; i <= b; i++) ve.eb(v[i], i);
    sort(ve.begin(), ve.end(), cmp);
    for(int i = p; i < ve.size(); i++) {
        //cout << "AA " << ve[i].se << endl;
        tira[ve[i].se] = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> p;
    for(int i = 0; i < n; i++) cin >> v[i];
    cin >> s;
    int cont = 0;
    for(int i = 1; i <= n; i++) {
        if(i < n and s[i] == s[i-1]) cont++;
        else {
            if(cont >= p) {
                choose(i-cont-1, i-1);
                //cout << i-cont-1 << endl;
                //cout << i-1 << endl;
            }
            cont = 0;
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) if(!tira[i]) ans += v[i];
    cout << ans << endl;
    return 0;
}

