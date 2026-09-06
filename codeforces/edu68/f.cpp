#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x) cout << #x << " = " << x << endl
#define ok cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const ll MOD = 1e9 + 7;
const int T = 2 * 1e5 + 4;
ll fat[T];

ll ele(ll b, ll e) {
  ll ans = 1;
  while (e) {
    if (e & 1)
      ans = ans * b % MOD;
    b = b * b % MOD;
    e >>= 1;
  }
  return ans;
}

ll modInverse(ll n) { return ele(n, MOD - 2); }

ll choose(ll n, ll k) {
  if (k < 0 || k > n)
    return 0;
  ll ans = fat[n];
  ll b = modInverse((fat[n - k] * fat[k]) % MOD);
  return ans * b % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  fat[0] = 1;
  for (ll i = 1; i < T; i++)
    fat[i] = (i * fat[i - 1]) % MOD;

  ll n, totalTime;
  cin >> n >> totalTime;
  vector<ll> ti;
  ti.pb(0);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    ti.pb(x);
  }

  ll timeSpent = 0;
  ll expectedValue = 0;
  ll goodFutures = 1;
  ll pascalColumn = 0;
  ll inversePossibleFutures = 1;

  for (ll i = 1; i <= n; i++) {
    timeSpent += ti[i];
    if (timeSpent > totalTime)
      break;

    ll currentPascalColumn = pascalColumn + 1;
    ll nextChunk = choose(i - 1, currentPascalColumn);
    goodFutures = (goodFutures * 2ll + nextChunk) % MOD;

    ll newPascalColumn = min(totalTime - timeSpent, i);

    while (currentPascalColumn > newPascalColumn) {
      ll badFutures = choose(i, currentPascalColumn);
      goodFutures = (goodFutures - badFutures + MOD) % MOD;
      currentPascalColumn--;
    }

    pascalColumn = newPascalColumn;

    inversePossibleFutures = (inversePossibleFutures * modInverse(2)) % MOD;
    ll prob = (goodFutures * inversePossibleFutures) % MOD;

    expectedValue = (expectedValue + prob) % MOD;
  }

  cout << expectedValue << endl;
  return 0;
}
