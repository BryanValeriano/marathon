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
const int T = 1e5 + 10;
int v[T];
ll aux[T];

int main() {
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    int op;
    ll x;
    ll val;
    ll inc = 0;
    for(int i = 0; i < m; i++) {
        cin >> op;
        if(op == 1) {
            cin >> x >> val;
            v[x] = val;
            aux[x] = inc;
        }
        else if(op == 2) {
            cin >> val;
            inc += val;
        } else {
            cin >> x;
            cout << v[x] + inc - aux[x] << endl;
        }
    }
    return 0;
}

