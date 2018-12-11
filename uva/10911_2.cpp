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
typedef vector< pair<double,double> > vdd;
const int INF = 0x3f3f3f3f;
const int T = 2e6;
int n, gol;
double dp[T];
vdd studs;

double dist(ii a, ii b) {
    return sqrt((pow(abs(a.fi-b.fi),2) + pow(abs(a.se-b.se),2)));
}

double solve(int k) {
    if(k == gol) return 0; 

    double &l = dp[k];
    if(l) return l;
    
    double ans = INF;
    for(int i = 0; i < 2*n; i++) {
        if(k & (1<<i)) continue;
        for(int j = 0; j < 2*n; j++) {
            if(k & (1<<j) or j == i) continue;
            int x = 0; x |= (1<<i); x |= (1<<j);
            double r = solve(k | x) + dist(studs[i],studs[j]);
            ans = min(ans,r);
        }
    }
    return l = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int a,b;
    string lixo;
    int cont = 0;
    while(n) {
        studs.clear();
        for(int i = 0; i < 2*n; i++) {
            cin >> lixo >> a >> b;
            studs.eb(a,b);
        }
        gol = 0;
        for(int i = 0; i < 2*n; i++) gol |= (1<<i);
        memset(dp, 0, sizeof dp);
        cout << "Case " << ++cont << ": ";
        cout << fixed << setprecision(2) << solve(0) << endl;
        cin >> n;
    }
    return 0;
}

