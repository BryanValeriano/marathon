#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string, string> ss;
typedef pair<string, ss> sss;
typedef pair<int, string> inst;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
string ori = "111";
string dest = "222"; 

map<string, vector<string> > g;
map<string,ss> pals;
map<string, int> best;

bool isEdge(map<string,ss>::iterator x, map<string,ss>::iterator y) {
    if(x->se.fi == y->se.fi or x->se.fi == y->se.se
        or x->se.se == y->se.fi or x->se.se == y->se.se)
        return true;
    return false;
}

int dij() {
    priority_queue<inst, vector< inst >, greater< inst > > pq;
    best[ori] = 0;
    pq.emplace(best[ori], ori);
    while(!pq.empty()) {
        inst tmp = pq.top();
        pq.pop();
        string atual = tmp.se;
        if(atual == dest) return best[atual] - dest.size();
        for(auto vis : g[atual]) {
            if(!best.count(vis) or best[atual] + vis.size() < best[vis]) {
                best[vis] = best[atual] + vis.size();
                pq.emplace(best[vis], vis);
            }
        }
    }
    return INF;
}

int main() {
    ios::sync_with_stdio(false);
    int m; cin >> m;
    string o,d;
    while(m) {
        cin >> o >> d;
        string a, b, c;
        g.clear();
        pals.clear();
        best.clear();
        for(int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            pals[c] = ss(a,b);
            if(a == o or b == o) g[ori].pb(c);
            if(a == d or b == d) g[c].pb(dest);
        }
        map<string,ss>::iterator it;
        map<string,ss>::iterator it2;
        for(it = pals.begin(); it != pals.end(); it++) {
            it2 = it;
            it2++;
            for(; it2 != pals.end(); it2++) 
                if(it->fi[0] != it2->fi[0] and isEdge(it, it2)) {
                    g[it->fi].pb(it2->fi);
                    g[it2->fi].pb(it->fi);
                }
        }            
        int ans = dij(); 
        if(ans >= INF-10) cout << "impossivel" << endl;
        else cout << ans << endl;
        cin >> m;   
    }

    return 0;
}

