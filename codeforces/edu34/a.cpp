#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x) cout << #x << " = " << x << endl
#define ok cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int dp[110];

bool solve(int x) {
    if(x == 0) return true;
    if(x < 0) return false;

    int &r = dp[x];
    if(r != -1) return r;

    bool ans = solve(x-7);
    ans |= solve(x-3);

    return r = ans;
}    

int main() {
	ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    int x;
    memset(dp, -1, sizeof dp);
    while(tc--) {
        cin >> x; 
        if(solve(x)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
}
