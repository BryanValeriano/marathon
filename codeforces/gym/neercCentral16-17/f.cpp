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

const int T = 1e3 + 5;

vii v;
int pai[T];
int peso[T];
int k[T];
int ans[T];
int n, m;

void init() {
    for(int i = 0; i < T; i++) {
        peso[i] = 1;
        pai[i] = i;
    }
}

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
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
    cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
 
    init();
    int x,y;
    char c;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        cin >> x >> c >> y;
        if(c == '=') join(x,y);
        else if(c == '>') v.pb({x,y});
        else v.pb({y,x});
    }
    
    for(int i = 0; i < v.size(); i++) k[find(v[i].fi)]++;

    for(int i = 0; i < v.size(); i++) {
        if(k[find(v[i].se)] > 0) {
            ans[find(v[i].fi)] = 1;
            ans[find(v[i].se)] = 2;
        }
    }

    for(int i = 0; i < v.size(); i++) 
        if(ans[find(v[i].fi)] == 2) ans[find(v[i].se)] = 3;

    string r;

    for(int i = 1; i <= n; i++) {
        int j = find(i);
        if(ans[j] == 0) r += "?";
        else if(ans[j] == 1) r += "W";
        else if(ans[j] == 2) r += "R";
        else r += "B";
    }

    cout << r << endl;

    return 0;
}

