#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

vi primeFactors(ll N) {
// remember: vi is vector<int>, ll is long long
vi factors;
ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
while (PF * PF <= N) {
// stop at sqrt(N); N can get smaller
while (N % PF == 0) { N /= PF; factors.push_back(PF); }
// remove PF
PF = primes[++PF_idx];
// only consider primes!
}
if (N != 1) factors.push_back(N);
// special case if N is a prime
return factors;
// if N does not fit in 32-bit integer and is a prime
}

ll sumDiv(ll N) {
    ll PF_idx = 0, PF = primes[PF_idx], ans = 1;

    while (PF * PF <= N) {
        ll power = 0;
        while (N % PF == 0) { N /= PF; power++; }
        ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);
        PF = primes[++PF_idx];
    }
    if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1); // last
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout << sumDiv(9) << endl;
    return 0;
}

