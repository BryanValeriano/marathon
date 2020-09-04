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
const int N = 10;
long double choose[N][N];

ll calc(ll i, ll j, ll n) {
    return ((j+1)*(i+1)*(n-j)*(n-i));
}

void pre() {
    for(int i = 0; i < N; i++) choose[i][0] = choose[i][i] = 1;
    for(int i = 1 ; i < N; i++)
        for(int j = 1 ; j < N; j++)
            choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    pre();
    freopen("fetiera.in", "r", stdin);
    int tc; cin >> tc;
    while(tc--) {
        ll n; cin >> n;
        int k; cin >> k;
        ll qtd = ((n*(n+1))>>1)*((n*(n+1))>>1);
        long double ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                char c; cin >> c;
                ll subs = calc(i,j,n);
                double p = (double)subs/(double)qtd;
                double par = (1 + pow(1-2*p,k))/2;
                double impar = (1 - pow(1 - 2 * p, k)) / 2;
                ans += (c=='0'? impar : par);
                //for(ll i = (c=='0'); i <= k; i += 2) ans += pow(prob,i) * pow(1 - prob, k - i) * choose[k][i];
            }
        }

        cout << fixed << setprecision(5) << ans << endl;
    }
    return 0;
}

