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

const double INF = 2e18;
const int T = 60;
const int N = pow(2,12) + 100;
double g[T][T];
pair<int,double> save[15];
double dp[T][N];
int n, p;

void reset() {
    for(int i = 0; i < T; i++)
        for(int j = 0; j < T; j++)
            g[i][j] = INF;
    for(int i = 0; i < T; i++) g[i][i] = (double)0;

    for(int i = 0; i < T; i++)
        for(int j = 0; j < N; j++)
            dp[i][j] = (double)-1;
}

double readD() {
    int a,b,c;
    char x;
    cin >> a >> x >> b;
    return double (a + ((double)b* 1e-2));
}

void floyd() {
    for(int k = 0; k < T; k++)
        for(int i = 0; i < T; i++)
            for(int j = 0; j < T; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

}

double solve(int atual, int mask) {
    double &r = dp[atual][mask];
    if(r != -1) return r;

    double ans = -g[atual][0];
    for(int i = 0; i < p; i++) 
        if(! (mask & (1<<i)) ) 
            ans = max(ans, solve(save[i].fi, mask | (1<<i)) + save[i].se - g[atual][save[i].fi]); 

    return r = ans;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int m;
    while(tc--) {
        cin >> n >> m;
        reset();
        int a,b;
        double d;
        for(int i = 0; i < T; i++) g[i][i] = 0;
        for(int i = 0; i < m; i++) {
            cin >> a >> b >> d;
            d = round(d*100);
            //d = readD();
            g[a][b] = min(g[a][b], d);
            g[b][a] = min(g[b][a], d);
        }
        cin >> p;
        for(int i = 0; i < p; i++) {
            cin >> a >> d;
            d = round(d*100);
            //d = readD();
            save[i] = mk(a,d);
        }
        floyd();
        double ans = 0;
        ans = max(ans, solve(0,0));
        if(ans > 0) cout << fixed << setprecision(2) << "Daniel can save $" << ans/100;
        else cout << "Don't leave the house";
        cout << endl;
    }
    //cout << endl;
    return 0;
}

