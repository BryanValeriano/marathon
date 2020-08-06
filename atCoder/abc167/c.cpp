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
const int T = 12;
vector<int> v[T+2];
int has[T+2];

int main() {
    ios_base::sync_with_stdio(false);
    int n,m,x; cin >> n >> m >> x;
    int gol = (1<<n);

    for(int i = 0; i < n; i++) {
        int c; cin >> c;
        v[i].pb(c);
        for(int j = 0; j < m; j++) {
            cin >> c;
            v[i].pb(c);
        }
    }

    bool ans = 0, ok = 0;
    int r = INF;

    for(int mask = 0; mask < gol; mask++) {
        memset(has,0,sizeof has);
        ok = 1;
        int cost = 0;
        for(int j = 0; j < n; j++) {
            if(mask&(1<<j)) {
                cost += v[j][0];
                for(int k = 1; k <= m; k++) has[k] += v[j][k];
            }
        }

        for(int j = 1; j <= m; j++) ok &= (has[j] >= x);
        if(ok) {
            ans |= ok;
            r = min(r,cost);
        }
    }

    cout << (ans?r:-1) << endl;
    return 0;
}

