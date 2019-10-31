#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define loop(x) for (int i = 0;i < x;i++)
#define each(x, xs) for (auto& x : xs)
#define iter(a) a.begin(), a.end()

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef tuple<int,int,int> ti;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 505;
const int M = 1e4 + 5;
int n, c;
int dp[N][M];
vector<ti> ds;

int solve(int at, int spc) {
    if(spc < 0) return -INF;
    if(at >= n) return 0;

    int &r = dp[at][spc];
    if(~r) return r;

    int L = -INF;
    if(spc >= get<0>(ds[at])) L = 1 + solve(at+1, spc- get<1>(ds[at]));
    int R = solve(at+1, spc);

    return r = max(L, R);
}

void recovery(int at, int spc) {
    if(at >= n or spc < 0) return;
    int L = -INF;
    if(spc >= get<0>(ds[at])) L = 1 + solve(at+1, spc-get<1>(ds[at]));
    int R = solve(at+1, spc);

    if(L > R) {
        cout << get<2>(ds[at]) << " ";
        return recovery(at+1, spc-get<1>(ds[at]));
    }
    return recovery(at+1, spc);
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >>n >>c;
    for(int i = 0; i < n; i++) {
        int x,y; cin >> x >> y;
        ds.eb(x,y,i+1);
    }

    sort(ds.begin(), ds.end(),
            [](const ti &a, const ti &b) {
            return (get<0>(a) - get<1>(a)) > (get<0>(b) - get<1>(b));

            });
    memset(dp, -1, sizeof dp);
    cout <<solve(0, c) <<endl;
    recovery(0, c);
    if(solve(0,c)) cout <<endl;

}
