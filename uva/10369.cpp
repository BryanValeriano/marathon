#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<double, ii> node;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 505;

int n,m;
vii v;
int pai[T];
int peso[T];


void init() {
    for(int i = 0; i < T; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
    v.clear();
}

int find(int x) {
    return (x == pai[x]? pai[x] : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if(peso[x] < peso[y]) swap(x,y);
    
    pai[x] = y;
    peso[x] += peso[y];
}

int main() {
    ios::sync_with_stdio(false);
    int tc, x, y; cin >> tc;
    while(tc--) {
        cin >> n >> m;
        init();
        for(int i = 0; i < m; i++) {
            cin >> x >> y;
            v.eb(x,y);
        }

        vector<node> pq;
        
        for(int i = 0; i < m; i++)
            for(int j = i + 1; j < m; j++)
                pq.pb({hypot(abs(v[i].fi - v[j].fi), abs(v[i].se - v[j].se)), ii(i,j)});

        sort(pq.begin(), pq.end(), greater<node>());
        
        int cp = m - n;
        double ans = 0;

        while(cp) {
            node at = pq.back();
            pq.pop_back();
            if(find(at.se.fi) != find(at.se.se)) {
                join(at.se.fi, at.se.se);
                cp--;
                ans = at.fi;
            }
        }

        cout << fixed << setprecision(2) << ans << endl;

    }

    return 0;
}

