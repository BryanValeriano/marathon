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
const int N = 2e5+2;
const int K = 11;
const ll MOD = 998244353;

ll dp[N];
int l[K], r[K];
int n,k;

ll inter(int pos, int k) {
    int ll = min(n+1,pos+l[k]);
    int rr = min(n+1,pos+r[k]+1);
    return (dp[ll]-dp[rr]+MOD)%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    dp[n] = 1;
    for(int i = 0; i < k; i++) cin >> l[i] >> r[i];

    for(int i = n-1; i >= 1; i--) {
        dp[i] = dp[i+1];
        for(int j = 0; j < k; j++)
            dp[i] = (dp[i] + inter(i,j))%MOD;
    }

    cout << (dp[1]-dp[2]+MOD)%MOD << endl;
    return 0;
}

