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
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int m, n;
  double r;
  cin >> m >> n >> r;
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int delx = abs(a - c);
  int dely = abs(b - d);
  int miny = min(b, d);
  double ans = INF;
  double seg = r / n;
  loop(miny + 1) {
    double dist = (dely + i + i) * seg;
    dist += PI / m * delx * seg * (miny - i);
    ans = min(ans, dist); 
  }
  cout << fixed << setprecision(7) << ans << endl;
	return 0;
}

