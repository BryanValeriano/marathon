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
const int T = 1e5 + 3;

int n,m;
unordered_set<int> g[T];
unordered_set<int> bag;
int ok[T][3];
int tam[3];
int mask[T];

void partiu() {
    cout << -1 << endl;
    exit(0);
}

void except(int x, int t) {
    for(int i = 1; i <= n; i++) {
        if(!g[x].count(i)) {
            if(!bag.count(i)) partiu();
            mask[i] = t;
            tam[t]++;
            bag.erase(i);
        }
    }
}

bool dontHave(int x) {
    for(int i = 0; i < 3; i++) {
        if(i == mask[x] and ok[x][i] > 0) return 1;
        if(i != mask[x] and ok[x][i] != tam[i]) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a,b; cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }

    for(int i = 1; i <= n; i++) bag.insert(i);

    except(1,0);

    if(!bag.size()) partiu();
    int x = *bag.begin();
    except(x,1);

    if(!bag.size()) partiu();
    x = *bag.begin();
    except(x,2);

    for(int u = 1; u <= n; u++) {
        for(int v : g[u]) ok[u][mask[v]]++;
        if(dontHave(u)) partiu();
    }

    for(int i = 1; i <= n; i++) cout << mask[i]+1 << " ";
    cout << endl;

    return 0;
}

