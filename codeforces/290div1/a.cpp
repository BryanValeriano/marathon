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
const int T = 102;
const int N = 30;
string s[T];
int in[N];
vector<int> g[N];
vector<int> ans;

bool lex(int x, int y) {
    for(int i = 0; i < min(s[x].size(), s[y].size()); i++) {
        if(s[x][i] != s[y][i]) {
            g[s[x][i]-'a'].pb(s[y][i]-'a');
            in[s[y][i]-'a']++;
            return true;
        }

    }

    return (s[x].size() < s[y].size());
}

bool topoSort() {
    queue<int> fila;
    for(int i = 0; i < 26; i++)
        if(!in[i]) fila.push(i);

    while(!fila.empty()) {
        int u = fila.front();
        fila.pop();
        ans.pb(u);
        for(int v : g[u]) {
            in[v]--;
            if(!in[v]) fila.push(v);
        }
    }

    return (ans.size()==26);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];

    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            if(!lex(i,j)) {
                cout << "Impossible\n";
                return 0;
            }

    if(topoSort()) {
        for(int x : ans) cout << ((char)(x + 'a'));
        cout << endl;
    } else cout << "Impossible\n";

    return 0;
}

