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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 22;

string var;
unordered_map<char,int> id;
string ok;
vector<int> g[T];
bool vis[T];
int in[T];
bool flag;
int c;
string ans;

void print() {
    for(int i = 0; i < c; i++) cout << ans[i] << (i+1 == c? "" : " ");
    cout << endl;
}

void dfs(int u) {
    ans += ok[u];
    vis[u] = 1;

    if(ans.size() == c) {
        print();
        flag = 0;
        vis[u] = 0;
        ans.pop_back();
        return;
    }

    for(int v : g[u]) in[v]--;
    for(int v = 0; v < c; v++) if(!in[v] and !vis[v]) dfs(v);
    for(int v : g[u]) in[v]++;
    vis[u] = 0;
    ans.pop_back();
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    getline(cin,var);
    while(tc--) {
        getline(cin,var);
        getline(cin,var);

        id.clear(); c = 0; ok = "";
        for(int i = 0; i < var.size(); i++)
            if(var[i] >= 'A' and var[i] <= 'Z') ok += var[i];

        sort(ok.begin(), ok.end());

        for(int i = 0; i < ok.size(); i++) {
            g[c].clear();
            in[c] = vis[c] = 0;
            id[ok[i]] = c++;
        }

        getline(cin,var);

        for(int i = 0; i < var.size(); i += 4)
            in[id[var[i+2]]]++, g[id[var[i]]].pb(id[var[i+2]]);

        flag = 1;
        for(int i = 0; i < c; i++)
            if(!in[i]) dfs(i);
        if(flag) cout << "NO" << endl;
        if(tc) cout << endl;
    }
    return 0;
}

