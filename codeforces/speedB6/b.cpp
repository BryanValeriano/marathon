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
 
const int T = 1e6 + 10;
ll skip = 2e4 + 5;
ll n,m;
ll v[T];
ll ans[T];
ll radius[T];
ll ori[T];
 
struct point { 
    ll x, y; 
    point(ll x, ll y) : 
        x(x), y(y) {}
};
 
bool inside(point p, point c, int r) {
    ll dx = p.x - c.x, dy = p.y - c.y;
    ll Euc = dx * dx + dy * dy, rSq = r*r;
    return Euc <= rSq ? 1 : 0;
}
        
 
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int x,y;
    int cont = 1;
 
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        x += skip;
 
        radius[cont] = y;
        ori[cont] = x;
        v[x-y+1] = cont;
        v[x+y-1] = cont;
        cont++;
    }
 
    int at = 0;
 
    for(int i = 0; i < T; i++) {
        if(v[i] and (!at) and radius[v[i]] > 1) at = v[i];
        else if(v[i]) at = 0;
        if(!v[i]) v[i] = at;
    }
 
    int m; cin >> m;
    int res = 0;
 
    for(int i = 1; i <= m; i++) {   
        cin >> x >> y;
        x += skip;
 
        for(int j = x-3; j <= x + 3; j++) 
            if(v[j] and !ans[v[j]] and inside(point(x,y), point(ori[v[j]], 0), radius[v[j]])) ans[v[j]] = i, res++;
    } 
 
    cout << res << endl;
    for(int i = 1; i <= n; i++) cout << (ans[i]? ans[i] : -1) << " ";
    cout << endl;
 
    return 0;
}
 
