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
const ll INF = 0x3f3f3f3f3f3f3fll;

const int T = 403;
ll mini[T][T][T];
ll maxi[T][T][T];
int id[T];
int n,r;
vii v;

void floydMin() {
    for(int i = 1; i <= n; i++) mini[i][i][i] = 0;

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                mini[i][j][k] = min(mini[i][k][k-1]+mini[k][j][k-1], mini[i][j][k]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> r;

    memset(maxi,INF,sizeof maxi);
    memset(mini,INF,sizeof mini);
    int id = 0;

    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        v.eb(x,i+1);
    }

    sort(v.begin(), v.end()); 

    ll last = -INF;
    int ok = 0;
    for(int i = 0; i < n; i++) {
        ok += (last < v[i].fi);
        id[v[i].se] = ok;
        last = v[i].fi;
    } 

    for(int i = 0; i < r; i++) {
        int a,b,d;
        cin >> a >> b >> d;
        mini[id[a]][id[b]][0] = d;
    }

    floyd(0);
    floyd(1);
    
    return 0;
}

