#include <bits/stdc++.h>
using namespace std;

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

const int T = 1e6+2;
bitset<T> crivo;
int qtd[T];
vector<ll> primes;
vii v[T];
int n;

void init() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

vii decop(int x) {
    vii tmp;
    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++) {
        if(x%primes[i]==0) {
            int ok = 0;
            while(x%primes[i]==0) x /= primes[i], ok++;
            tmp.eb(primes[i],ok);
            qtd[primes[i]] += ok;
        }
    }

    if(x > 1) {
        tmp.eb(x,1);
        qtd[x]++;
    }

    return tmp;
}

bool pairW() {
    bool ok = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < v[i].size(); j++)
            ok &= qtd[v[i][j].fi] == v[i][j].se;
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false);
    init();
    cin >> n;
    int gcd = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v[i] = decop(x);
        gcd = __gcd(gcd,x);
    }
    cout << (pairW()? "pairwise coprime" : gcd == 1? "setwise coprime" : "not coprime") << endl;
    return 0;
}

