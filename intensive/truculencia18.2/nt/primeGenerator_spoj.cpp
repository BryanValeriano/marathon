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
const int T = 4e4;
bitset<T> crivo;
vector<int>primes;

void gen() {
    for(int i = 2; i < T; i++) {
        if(crivo[i] == false) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = true;
        }
    }
}

bool isP(ll x) {
    if(x < 2) return false;
    for(int i = 0; i < primes.size(); i++) {
        if(primes[i] == x) return true;
        if(x % primes[i] == 0) return false;
    }
    return true;
}

int main() {
    gen();
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        ll l, h;
        scanf("%lld %lld", &l, &h);
        for(ll i = l; i <= h; i++) 
            if(isP(i)) printf("%lld\n", i);
        printf("\n");
    }
    return 0;
}

