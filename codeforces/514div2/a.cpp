#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int n, l, a; cin >> n >> l >> a;
    vector<pair<int,int> >vis;
    int c, b;
    for(int i = 0; i < n; i++) {
        cin >> c >> b;
        vis.pb(mp(c,b));
    }
    int i = 0;
    int cont = 0;
    int x = 0;

    while(i < l) {
        if(x < n && vis[x].fi >= i + a && i + a <= l) {
            int lim = (vis[x].fi - i)/a;
            cont+= lim;
            i = vis[x].fi;
        
        } 
        else if(x >= n && i + a <= l) {
            int lim = (l - i)/a;
            cont += lim;
            i = l;
        } 
        else if(x < n) {
            i = vis[x].fi;
            i += vis[x].se;
            x++;
        } else {
            i = l;
        }
    }
    cout << cont << endl;

    return 0;
}

