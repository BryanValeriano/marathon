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
const int T = 1e3+5;
vii v;
int qtd[T];
vector<int> ans;
set<int> bag;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int l,r; cin >> l >> r;
        v.eb(l,r);
    }

    sort(v.begin(),v.end());

    int m; cin >> m;
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        bag.insert(x);
        for(int i = 0; i < n; i++)
            if(x >= v[i].fi and x <= v[i].se) qtd[i]++;
    }

    qtd[n] = INF;

    for(int i = 0; i < n; i++) {
        bool ponta = 0;

        if(qtd[i] > 2) {
            cout << "impossible\n";
            return 0;
        }

        while(qtd[i] < 2) {
            int gol = v[i].se-(qtd[i+1] > 1);
            while(bag.count(gol)) gol--;
            ans.pb(gol);
            bag.insert(gol);
            qtd[i]++;
            if(gol == v[i].se) ponta = 1;
        }
        if(ponta and (i+1) < n and v[i].se == v[i+1].fi) qtd[i+1]++;
    }

    cout << ans.size() << endl;
    for(int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

