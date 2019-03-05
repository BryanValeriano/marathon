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

const int T = 5e3 + 100;
const int S = 3e5 + 10;
const int N = 1e7 + 5e6 + 10;
bitset<T> crivo;
int cont[N];
vector<int> primes;
int v[S];

void gen() {
    for(int i = 2; i < T; i++) {
        if(crivo[i] == false) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = true;
        }
    }
}

void decop(int x) {
    int i = 0;
    while(i < primes.size() and primes[i] * primes[i] <= x) {
        if(x % primes[i] == 0)  cont[primes[i]]++;
        while(x % primes[i] == 0) { 
            x /= primes[i];
        }
        i++;
    }
    if(x > 1) cont[x]++;
}

int main() {
    int n; scanf("%d", &n);
    int x;
    gen();
    int gcd = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        gcd = __gcd(gcd, v[i]);
    }
    for(int i = 0; i < n; i++) decop(v[i]/gcd);

    int maxi = 0;

    for(int i = 2; i < N; i++) if(cont[i] > maxi) maxi = cont[i];

    printf("%d\n", maxi != 0? n-maxi : -1); 
    return 0;
}

