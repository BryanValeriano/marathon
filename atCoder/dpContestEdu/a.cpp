#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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
const int N = 1e5 + 3;
int h[N];
int dp[N];

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, INF, sizeof dp);
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> h[i];

    dp[0] = 0;
    for(int i = 1; i < n; i++)
        for(int j = max(0,i-2); j < i; j++)
            dp[i] = min(dp[i], dp[j] + abs(h[i]-h[j]));

    cout << dp[n-1] << endl;
    return 0;
}

