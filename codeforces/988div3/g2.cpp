#include <bits/stdc++.h>
using namespace std;

// Macros for convenience
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'

// Typedefs for readability
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

// Constants
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const ll MOD = 998244353;
const int T = 1e6 + 6;

// Global Arrays
ll resp[T];            // Stores the cumulative counts for each factor
bool isPrimeFlag[T];   // Sieve array to mark non-prime numbers
vector<int> allPrimes; // List of all prime numbers up to T

// Sieve of Eratosthenes to generate primes up to T
void sieve() {
  fill(isPrimeFlag, isPrimeFlag + T, false);
  for (int i = 2; i < T; i++) {
    if (!isPrimeFlag[i]) {
      allPrimes.pb(i);
      for (int j = i * 2; j < T;
           j += i) { // Start from 2*i to avoid marking the prime itself
        isPrimeFlag[j] = true;
      }
    }
  }
}

// Precompute primes
void precomputePrimes() { sieve(); }

// Function to get distinct prime factors of x using the allPrimes list
vector<int> getPrimes(int x) {
  vector<int> primes;
  for (auto &prime : allPrimes) {
    if (prime * (ll)prime > x)
      break;
    if (x % prime == 0) {
      primes.pb(prime);
      while (x % prime == 0) {
        x /= prime;
      }
    }
  }
  if (x > 1) {
    primes.pb(x);
  }
  return primes;
}

// Template function to iterate through all non-empty subsets of prime factors
// and pass both factor and mask to the callback function
template <typename Func> void doSomethingForEachFactor(int x, Func func) {
  vector<int> primes = getPrimes(x);
  int k = primes.size();
  // Iterate through all non-empty subsets using bitmasking
  for (int mask = 1; mask < (1 << k); mask++) {
    ll factor = 1;
    for (int primePos = 0; primePos < k; primePos++) {
      if (mask & (1 << primePos)) {
        factor *= primes[primePos];
      }
    }
    func(factor,
         mask); // Invoke the passed function with the computed factor and mask
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  precomputePrimes(); // Precompute primes using sieve

  int n;
  cin >> n; // Number of cities

  int firstCityAttractiveness;
  cin >> firstCityAttractiveness; // Attractiveness of the first city

  // Initialize resp for the first city (City 1)
  // dp[1] = 1 implies that there's exactly one path starting at City 1
  doSomethingForEachFactor(firstCityAttractiveness, [&](ll factor, int mask) {
    resp[factor] = (resp[factor] + 1) % MOD; // Each subset contributes one path
  });

  ll dp_prev = 1; // dp[1] = 1

  // Iterate through cities 2 to n
  for (int city = 2; city <= n; city++) {
    int currentAttractiveness;
    cin >> currentAttractiveness; // Attractiveness of the current city

    ll tot = 0; // Total number of paths to the current city

    // Compute 'tot' using inclusion-exclusion based on current city's prime
    // factors
    doSomethingForEachFactor(currentAttractiveness, [&](ll factor, int mask) {
      int bits = __builtin_popcount(mask); // Number of primes in the subset
      if (bits % 2 == 1) {
        tot = (tot + resp[factor]) % MOD; // Add if subset size is odd
      } else {
        tot =
            (tot - resp[factor] + MOD) % MOD; // Subtract if subset size is even
      }
    });

    // Update 'resp' for the current city by adding 'tot' to all its subset
    // factors
    doSomethingForEachFactor(currentAttractiveness, [&](ll factor, int mask) {
      resp[factor] = (resp[factor] + tot) % MOD;
    });

    dp_prev = tot; // Update dp_prev for the next iteration
    cout << tot << endl;
  }

  cout << dp_prev % MOD
       << endl; // Output the total number of distinct paths to City n
  return 0;
}
