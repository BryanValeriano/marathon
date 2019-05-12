#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 2e5 + 10;
int peso[T];
int pai[T];
unordered_map<string,int> names;
int t;

void init(int n) {
    for(int i = 0; i < n; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
    names.clear();
    t = 0;
}

int ind(string x) {
    if(names.count(x)) return names[x];
    names[x] = ++t;
    return t;
}

int find(int x) {
    return (x == pai[x]? pai[x] : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    string x,y;
    while(tc--) {
        int m; cin >> m;
        init(m*2);
        while(m--) {
            cin >> x >> y;
            join(ind(x), ind(y));
            cout << peso[find(ind(x))] << endl;
        }
    }
    return 0;
}

