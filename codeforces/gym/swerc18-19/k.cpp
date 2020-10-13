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
const int N = 705;
int pi[N];
int compress[N][N];
int dp[N][N];
string p,t;

void pre(string s) {
	p = s+'#';
	for (int i = 1; i < (int)p.size(); i++) {
		pi[i] = pi[i-1];
		while(pi[i] > 0 and p[pi[i]] != p[i]) pi[i] = pi[pi[i]-1];
		if(p[pi[i]] == p[i]) pi[i]++;
	}
}

int solve(int l, int r) {
    if(r==l) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    dp[l][r] = 0;

    for(int i = 0; l+i < r; i++)
        dp[l][r] = max(dp[l][r], solve(l,l+i) + solve(l+i+1,r));

    if(compress[l][r] != l-r+1) {
        int k = compress[l][r];
        dp[l][r] = max(dp[l][r], solve(l,l+k-1) + (r-l+1-k));
    }

    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    int n; cin >> n;
    string s; cin >> s;

    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int size = j-i+1;
            pre(s.substr(i,j-i+1));
            int k = size-pi[size-1];
            compress[i][j] = (!k or size%k?size:k);
        }
    }

    cout << (n-solve(0,n-1)) << endl;
    return 0;
}

