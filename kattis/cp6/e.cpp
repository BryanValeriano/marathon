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
set<string> vis;
map<string,string> pai;

string add(string s, int pos, int val) {
    s[pos] += val;
    if(s[pos] < '0') s[pos] = '9';
    if(s[pos] > '9') s[pos] = '0';
    return s;
}

bool valid(string s) {
    return (s[3] <= '5' and s[0] <= '2' and (s[0] == '2'? s[1] <= '3' : 1));
}

void bfs(string s, string t) {
    vector<string> ans;
    queue<string> fila;
    fila.push(s);
    vis.insert(s);

    while(!fila.empty()) {
        string at = fila.front();
        fila.pop();
        if(at == t) break;

        for(int i = 0; i < 5; i++) {
            if(i == 2) continue;
            for(int j = -1; j < 2; j++) {
                if(!j) continue;
                string v = add(at,i,j);
                if(vis.count(v) or !valid(v)) continue;
                pai[v] = at;
                vis.insert(v);
                fila.push(v);
            }
        }

    }

    while(t != s) {
        ans.pb(t), t = pai[t];
    }
    ans.pb(s);
    cout << ans.size() << endl;
    for(int i = ans.size()-1; i >= 0; i--) cout << ans[i] << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    string s,t; cin >> s >> t;
    bfs(s,t);
    return 0;
}

