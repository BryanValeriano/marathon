#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>         vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          (l + r) >> 1
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string s;
  cin >> s;
  int x = 0;
  int c = 0, sig = 1;
  mii cs;
  bool e = false;
  for (int i = 0;;i++) {
    if (isdigit(s[i])) {
      x += s[i] - '0';
    }
    else {
      if (s[i] == 'x') {
        e = true;
        if (x == 0) x = 1;
        c = x * sig;
      }
      else {
        if (e) cs[s[i - 1] == 'x' ? -1 : -x] = c;
        else cs[0] = x;
        e = false;
        if (s[i] == '-') sig = -1;
        else if (s[i] == '+') sig = 1;
        else break;
      }
      x = 0;
    }
  }
  bool first = true, null = true;
  for (auto [g, c] : cs) {
    int e = -g;
    if (e and c) {
      if (!first and c > 0) cout << "+";
      cout << c * e;
      if (e > 1) cout << "x";
      if (e > 2) cout << e - 1;
      first = false;
      null = false;
    }
  }
  if (null) cout << 0 << endl;
  return 0;
}

