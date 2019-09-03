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
ii ve[T];

bool cmp(const ii &a, const ii &b) {
    if(a.fi != b.fi) return a.fi > b.fi;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        ve[i] = mk(v[i], i);
    }
    nth_element(ve, ve+(m*k), ve+n, cmp);
    ll sum = 0; 
    set<int> pegos;
    vector<int> ans;
    for(int i = 0; i < m*k; i++) {
        sum += ve[i].fi;
        pegos.insert(ve[i].se);
    }
    int cont = 0;
    for(int i = 0; i < n and ans.size() < k-1; i++) {
        if(pegos.count(i)) cont++;
        if(cont == m) {
            ans.pb(i+1);
            cont = 0;
        }
    }
    cout << sum << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

