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
const int T = 10000000;
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

int solve(int a, int b) {
    int n = 0;
    while(1) {
        int z = n*n + a*n + b;
        if(z < 0 or crivo[z]) break;
        n++;
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(false);
    primes.pb(1);
    init();
    int qtd = 0;
    int ans = 0;

    for(int i = 0; primes[i] < 1000; i++) {
        for(int j = 0; primes[j] <= 1000; j++) {
            int x = solve(primes[i],primes[j]);
            int y = solve(-primes[i],primes[j]);
            if(x > qtd) qtd = x, ans = primes[i]*primes[j];
            if(y > qtd) qtd = y, ans = -primes[i]*primes[j];
        }
    }

    cout << qtd << " " << ans << endl;

    return 0;
}

