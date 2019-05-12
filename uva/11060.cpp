#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,string> si;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

unordered_map<string, int> in;
unordered_map<string, int> prioridade;
unordered_map<string, vector<string> > g;
int n;

void init() {
    in.clear();
    g.clear();
    prioridade.clear();
}

void read() {
    string s, l;
    for(int i = 0; i < n; i++) {
        cin >> s;
        in[s] = 0;
        prioridade[s] = n-i;
    }

    int m; cin >> m;

    for(int i = 0; i < m; i++) {
        cin >> s >> l;
        g[s].pb(l);
        in[l]++;
    }
}

void solve() {
    priority_queue<si, vector<si> > lista;
    for(auto s : in) if(s.se == 0) lista.emplace(prioridade[s.fi], s.fi);

    while(!lista.empty()) {
        si tmp = lista.top();
        string at = tmp.se;
        lista.pop();
        cout << " " << at;
        for(auto x : g[at]) {
            in[x]--;
            if(!in[x]) lista.emplace(prioridade[x], x);
        }
    }
    cout << "." << endl << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int cont = 0;
    while(cin >> n) {
        init();
        read();
        cout << "Case #" << ++cont << ": Dilbert should drink beverages in this order:";
        solve();
    }
    return 0;
}

