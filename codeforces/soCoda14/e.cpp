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
const int T = 1e5 + 5;

vector<int> need[T];
vector<int> in[T];
vector<int> v[T];
int n,k,m;

bool solve() {
    int niv = 0;
    int root = need[0][0];
    in[0].pb(root);
    int prox = 1;
    int at = 0;

    while(need[prox].size()) {
        if(!in[niv].size()) break;

        for(int at : in[niv]) {
            if(!need[prox].size()) break;

            m++;
            v[at].pb(need[prox].back());
            in[prox].pb(need[prox].back());

            need[prox].pop_back();
            if(v[at].size() + (at != root) > k) return 0;
        }

        if(!need[prox].size()) niv++, prox++;
    }

    return (m == n-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    int corn = 0;

    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        need[x].pb(i);
        if(x == 0) corn++;
    }

    if(corn != 1) {
        cout << -1 << endl;
        return 0;
    }

    if(!solve()) {
        cout << -1 << endl;
    } else {
        cout << m << endl;
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < v[i].size(); j++)
                cout << i << " " << v[i][j] << endl;
    }

    return 0;
}

