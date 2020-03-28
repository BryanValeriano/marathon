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
const int T = 5e3 + 2;
int n,m;
int pai[T];
int peso[T];
map<string,int> id;

void init() {
    for(int i = 0; i <= n; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
    id.clear();
}

int find(int x) {
    return (pai[x] == x? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(peso[y] > peso[x]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    while(n or m) {
        init();

        while(n--) {
            string s; cin >> s;
            id[s] = n;
        }
        while(m--) {
            string s,t; cin >> s >> t;
            join(id[s],id[t]);
        }

        int ans = 0;
        for(auto x : id) ans = max(ans, peso[find(x.se)]);
        cout << ans << endl;

        cin >> n >> m;
    }
    return 0;
}

