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

const int T  = 1e5 + 10;
int hn[T];
int hs[T];
int ve[T];
int vw[T];
int n,q;

ii solve() {
    int bestx = 0;
    int besty = 0;
    int x = 0;
    int y = 0;

    for(int i = 1; i <= q; i++) {
        hn[i] += hn[i-1];
        ve[i] += ve[i-1];
    }
    for(int i = q-1; i >= 0; i--) {
        hs[i] += hs[i+1];
        vw[i] += vw[i+1];
    }

    for(int i = 0; i <= q; i++) {
        hn[i] += hs[i];
        ve[i] += vw[i];
        if(hn[i] > besty) {
            besty = hn[i];
            y = i;
        }
        if(ve[i] > bestx) {
            bestx = ve[i];
            x = i;
        }
    }
    return mk(x,y);
}


void read() {
    cin >> n >> q;
    int x,y;
    char d;
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> d;
        if(d == 'N') hn[y+1]++;
        else if(d == 'S') hs[y-1]++;
        else if(d == 'E') ve[x+1]++;
        else vw[x-1]++;
    }
}


int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        memset(ve,0,sizeof ve);
        memset(vw,0,sizeof vw);
        memset(hn,0,sizeof hn);
        memset(hs,0,sizeof hs);
        read();
        ii ans = solve();
        cout << "Case #" << ++cont << ": " << ans.fi << " " << ans.se << endl;
    }

    return 0;
}

