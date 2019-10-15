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

const int T = 1e6 + 5;
bitset<T> crivo;
vector<int> mask;
vector<int> wat;
vector<int> primes;

void init() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

void allMask() {
    for(int i = 1; i <= 64; i++) {
        int x = i;
        int casa = 1;
        int ans = 0;
        while(x) {
            if(x&1) ans += casa;
            casa *= 10;
            x >>= 1;
        }
        mask.pb(ans);
        wat.pb(i);
    }
}

bool ok(int x, int y) {
    int eq = -1;
    while(y) {
        if(y&1) {
            if(eq == -1) eq = x%10;
            else if(eq != x%10) return 0;
        }
        x /= 10;
        y >>= 1;
    }
    return 1;
}

int f(int i, int j) {
    while(j) {
        if(j&1) return i%10;
        j /= 10;
        i /= 10;
    }
    return 1;
}

int qtd(int i, int j) {

    int ini = f(i,j);
    if(ini > 2) return 0;
    int ans = 1;

    while(ini < 9) {
        if(!crivo[i+j]) ans++;
        ini++;
        i+=j;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    init();
    allMask();

    for(int i = 0; i < primes.size(); i++) {
        for(int j = 1; j < mask.size() and mask[j] <= primes[i]; j++) {
            if(!ok(primes[i], wat[j])) continue;
            if(qtd(primes[i],mask[j]) == 8) { cout << primes[i] << endl; return 0; }
        }
    }

    return 0;
}

