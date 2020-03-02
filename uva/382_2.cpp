#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = sqrt(6e4) + 10;
bitset<T> crivo;
vector<int> primes;

void init() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

ll sumDiv(ll x) {
    ll ans = 1;
    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++) {
        ll power = 0;
        while(x % primes[i] == 0) x /= primes[i], power++;
        ans *= ((ll)pow((double)primes[i], power + 1.0) - 1) / (primes[i]-1);
    }
    if(x != 1) ans *= ((ll)pow((double)x, 2.0) - 1) / (x-1);
    return ans;
}

int main() {
    int x;
    init();
    printf("PERFECTION OUTPUT\n");
    scanf("%d", &x);
    while(x) {
        printf("%5d  ",x);
        ll y = sumDiv(x) - x;
        if(y < x) printf("DEFICIENT\n");
        else if(y > x) printf("ABUNDANT\n");
        else printf("PERFECT\n");
        scanf("%d", &x);
    }
    printf("END OF OUTPUT\n");
    return 0;
}

