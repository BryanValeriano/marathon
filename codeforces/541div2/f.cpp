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

const int T = 2e5;

list<int> ans[T];
int pai[T];
int tam[T];

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(tam[x] < tam[y]) swap(x,y);
    tam[x] += tam[y];
    pai[y] = x;
    ans[x].splice(ans[x].end(), ans[y]);
}

void init(int n) {
    for(int i = 1; i <= n; i++) {
        ans[i].pb(i);
        pai[i] = i;
        tam[i] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,a,b; cin >> n;
    init(n);

    for(int i = 0; i < n-1; i++) {
        cin >> a >> b;
        join(a,b);
        if(i == n-2) for(auto x : ans[find(a)]) cout << x << " ";
    }
    cout << endl;

    return 0;
}

