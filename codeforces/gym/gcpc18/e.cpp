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
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

struct frac {
  ll n, d;
  frac(string s) : n(0), d(1) {
    bool dec = false;
    each(c, s) {
      if (c == '.') dec = true;
      else {
        n *= 10;
        n += c - '0';
        if (dec) d *= 10;
      }
    }
    simpl();
  }
  void simpl() {
    ll m = gcd(n, d);
    if (m) {
      n /= m;
      d /= m;
    }
  }
  void operator/=(frac& f) {
    n *= f.d;
    d *= f.n;
    simpl();
  }
};

const int T = 1e8;
bitset<T> isprime;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  isprime[0] = isprime[1] = true;
  for (int i = 4;i < T;i += 2) isprime[i] = true;
  for (int i = 3;i < T;i += 2) {
    if (isprime[i]) continue;
    for (int j = i + i;j < T;j += i) isprime[j] = true;
  }

  int n;
  cin >> n;
  string s, t;
  loop(n) {
    cin >> s >> t;
    frac f(s), g(t);
    f /= g;
    if (f.n < T and !isprime[f.n] and f.d < T and !isprime[f.d]) cout << f.n << " " << f.d << endl;
    else if(f.n == f.d) cout << "2 2\n";
    else cout << "impossible" << endl;
    //cout << f.n << " / " << f.d << endl;
  }
  return 0;
}

