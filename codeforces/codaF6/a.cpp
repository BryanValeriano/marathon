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
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 3e5 + 5;
vti g[T];
ll dist[T];
ll minL[T];
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a,b,w; cin >> a >> b >> w;
        g[a].eb(b,w,i);
        g[b].eb(a,w,i);
    }
    dij(1);



    return 0;
}

