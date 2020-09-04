#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

int dp[101][101][2][2];
bool vis[101][101][2][2];

int solve(int p, int q, bool dark, bool maxi) {
  if (p == 0 or q == 0) return 0;
  if (!vis[p][q][dark][maxi]) {
    int ans;
    if (maxi) {
      ans = -INF;
      for (int i = 1;i <= p;i++) {
        ans = max(ans, solve(p - i, q, dark ^ (i & 1), false) + (q & 1) * (i & 1) * (dark ? 1 : -1));
      }
    }
    else {
      ans = INF;
      for (int i = 1;i <= q;i++) {
        ans = min(ans, solve(p, q - i, dark ^ (i & 1), true) - (p & 1) * (i & 1) * (dark ? 1 : -1));
      }
    }
    dp[p][q][dark][maxi] = ans;
  }

  vis[p][q][dark][maxi] = 1;
  return dp[p][q][dark][maxi];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  int p, q;
  cin >> p >> q;
  cout << solve(q, p, true, true) << endl;
	return 0;
}

