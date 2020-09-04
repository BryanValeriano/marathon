#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<double,int> di;
typedef tuple<double,int,int> ti;
typedef vector<di> vdi;
typedef vector<ti> vti;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int T = 2e5+5;

map<string,int> id;
int ids;
double dist[T];
vti ve;

int getId(string s) {
    if(id.count(s)) return id[s];
    id[s] = ++ids;
    return ids;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 1; i <= n; i++) {
        string s,t;
        double r;
        cin >> s >> t >> r;
        ve.eb(log10(r),getId(t),getId(s));
    }

    getId("pink");
    getId("blue");

    for(int i= 1; i <= ids; i++) dist[i] = -INF;
    dist[getId("pink")] = 0;

    for(auto& [r,u,v] : ve) {
        if(abs(dist[u]-INF) < EPS) continue;
        dist[v] = max(dist[v], dist[u]+r);
    }

    int ok = getId("blue");
    if(abs(dist[ok]-INF)< EPS) cout << fixed << setprecision(6) << 0 << endl;
    else cout << fixed << setprecision(6) << pow(10,min(1.0,dist[ok])) << endl;

    return 0;
}

