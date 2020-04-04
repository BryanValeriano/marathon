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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = (1 << 20);

int dist[T];
bool vis[T];
queue<int> fila;
int m;

int mask(string s) {
    int ans = 0;
    for(int i = 0; i < m; i++)
        if(s[i] == '1') ans += (1 << i);
    return ans;
}

int bfs() {
    int ans = fila.front();
    int best = 0;

    while(!fila.empty()) {
        int at = fila.front();
        fila.pop();

        if(dist[at] > best) {
            best = dist[at];
            ans = at;
        }

        for(int i = 0; i < m; i++) {
            int ok = at^(1<<i);
            if(!vis[ok]) {
                vis[ok] = 1;
                dist[ok] = dist[at]+1;
                fila.push(ok);
            }
        }
    }

    return ans;
}

string solve() {
    int x = bfs();
    string ans;

    for(int i = 0; i < m; i++)
        ans += (x&(1<<i)? "1" : "0");

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        int x = mask(s);
        vis[x] = 1;
        fila.push(x);
    }

    cout << solve() << endl;

    return 0;
}

