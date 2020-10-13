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
const int T = 2e5+5;
int pai[T], peso[T],n,m;

void init(int n) {
    for(int i = 1; i <= n; i++) {
        pai[i] = i;
        peso[i] = 1;
    }
}

int find(int x) {
    return (x==pai[x]?x:pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y) return;
    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;
    peso[x] += peso[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    init(n);
    int ans = 0;
    while(m--) {
        int x,y; cin >> x >> y;
        join(x,y);
    }
    for(int i = 1; i <= n; i++) ans = max(ans,peso[find(i)]);
    cout << ans << endl;
    return 0;
}

