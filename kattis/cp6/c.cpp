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
const int T = 1e6;

map<string,int> bag;
vector<int> g[T];
int pai[T], vis[T];;
string volta[T];
int vez, cont;

int id(string s) {
    if(bag.count(s)) return bag[s];
    volta[++cont] = s;
    return bag[s] = cont;
}

bool add(string s) {
    if(bag.count(s)) return 0;
    string t = s;
    for(int i = 0; i < s.size(); i++) {
        t[i] = '*';
        g[id(s)].pb(id(t));
        g[id(t)].pb(id(s));
        t[i] = s[i];
    }
    return 1;
}

void solve(string ss, string tt) {
    int s = id(ss);
    int t = id(tt);

    swap(s,t);
    vez++;
    queue<int> fila;
    fila.push(s);
    vis[s] = vez;

    if(ss.size() == tt.size()) {

        while(!fila.empty()) {
            int at = fila.front();
            if(at == t) break;
            fila.pop();
            for(int v : g[at]) {
                if(vis[v] != vez) {
                    vis[v] = vez;
                    pai[v] = at;
                    fila.push(v);
                    if(v == t) break;
                }
            }
        }
    }

    if(vis[t] == vez) {
        bool ok = 1;
        while(t != s) {
            if(ok) cout << volta[t]<< endl;
            t = pai[t];
            ok = !ok;
        }
        cout << tt << endl;
    } else cout << "No solution.\n";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s,t;
    cin >> s;
    while(add(s)) cin >> s;
    cin >> t;
    solve(s,t);
    while(cin >> s) {
        cin >> t;
        solve(s,t);
    }
    return 0;
}

