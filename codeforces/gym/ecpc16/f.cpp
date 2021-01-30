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
typedef tuple<int,int,int> ti;
typedef vector<ii> vii;
typedef vector<ti> vti;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e6;
const int N = 5e5;
vti a[2][T];
int r[T];
int id;

int solve(int t, int pos) {
    sort(a[t][pos].begin(),a[t][pos].end());
    int maxi = 0;

    for(auto [k,ig,d] : a[t][pos]) {
        if(!ig) r[d] = maxi+1;
        else maxi = max(maxi,r[d]);
    }

    return maxi;
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("bishops.in","r",stdin);
    int tc; cin >> tc;

    while(tc--) {
        ll s,n,c;
        cin >> s >> n >> c;
        for(int i = 0; i <= id; i++) r[i] = 0;
        id = 0;

        for(int i = 0; i <= s+s; i++) {
            a[0][i].clear();
            a[1][N-i].clear();
            a[1][N+i].clear();
        }

        for(int i = 0; i < n; i++) {
            ll x,y,p; cin >> x >> y >> p;
            a[0][x+y].eb(y-p*p+1,0,++id);
            a[0][x+y].eb(y+p*p+c-1,1,id);
            a[1][N+(x-y)].eb(y-p*p+1,0,++id);
            a[1][N+(x-y)].eb(y+p*p+c-1,1,id);
        }

        int ans = 0;
        for(int i = 0; i <= s+s; i++) {
            ans = max(ans, solve(0,i));
            ans = max(ans, solve(1,N-i));
            ans = max(ans, solve(1,N+i));
        }
        cout << ans << endl;
    }
    return 0;
}
