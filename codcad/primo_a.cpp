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
const int T = 1e7 + 100;
vector<ll> primes;

bool isPrime(ll x) {
    if(x == 1) return true;
    for(ll i = 2; i * i <= x; i++) 
        if(x % i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    ll x;
    cin >> x;
    cout << (isPrime(x)? "N" : "S") << endl;
    return 0;
}

