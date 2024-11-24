#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const ll MOD = 998244353;
const int T = 1e6 + 6;
ll resp[T];
bool notPrime[T];
vector<int> allPrimes;

void sieve() {
  for (int i = 2; i < T; i++) {
    if (!notPrime[i]) {
      allPrimes.pb(i);
      for (int j = 2 * i; j < T; j += i) {
        notPrime[j] = 1;
      }
    }
  }
}

void pre() { sieve(); }

vector<int> getPrimes(int x) {
  vector<int> primes;
  ll i = 0;
  ll prime = allPrimes[i];
  while (prime * prime <= x) {
    if (x % prime == 0) {
      primes.pb(prime);
      while (x % prime == 0) {
        x /= prime;
      }
    }
    prime = allPrimes[++i];
  }
  if (x != 1)
    primes.pb(x);
  return primes;
}

template <typename Func> void doSomethingForEachFactor(int x, Func func) {
  vector<int> primes = getPrimes(x);
  int k = primes.size();
  for (int mask = 1; mask < (1 << k); mask++) {
    int factor = 1;
    for (int primePos = 0; primePos < k; primePos++) {
      if (mask & (1 << primePos)) {
        factor *= primes[primePos];
      }
    }
    func(factor, mask);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  pre();
  int n;
  cin >> n;
  int x;
  cin >> x;
  doSomethingForEachFactor(x, [&](int factor, int mask) { resp[factor] = 1; });
  ll tot = 0;
  for (int i = 1; i < n; i++) {
    tot = 0;
    int x;
    cin >> x;
    doSomethingForEachFactor(x, [&](int factor, int mask) {
      if (__builtin_popcount(mask) & 1) {
        tot = (tot + resp[factor]) % MOD;
      } else {
        tot = (tot - resp[factor] + MOD) % MOD;
      }
    });
    doSomethingForEachFactor(x, [&](int factor, int mask) {
      resp[factor] = (resp[factor] + tot) % MOD;
    });
  }
  cout << tot << endl;
  return 0;
}
