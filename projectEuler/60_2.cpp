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

const int T = 1e6 + 10;
bitset<T> crivo;
vector<int> primes;

void init() {
    crivo[0] = crivo[1] = 1;
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

void print(int a, int b, int c, int d, int e) {
    cout << primes[a] << endl;
    cout << primes[b] << endl;
    cout << primes[c] << endl;
    cout << primes[d] << endl;
    cout << primes[e] << endl;
    cout << primes[a]+primes[b]+primes[c]+primes[d]+primes[e] << endl;
    cout << endl;
}

ll junt(int x, int y) {
    ll ans = 0;
    ll casa = 1;

    while(y) {
        ans += (y%10)*casa;
        casa *= 10;
        y /= 10;
    }
    while(x) {
        ans += (x%10)*casa;
        casa *= 10;
        x /= 10;
    }

    return ans;
}

bool isPrime(ll x) {
    for(int i = 0; i < primes.size() and (ll)primes[i]*(ll)primes[i] <= x; i++) {
        if(x % primes[i] == 0) return 0;
    }
    return 1;
}

bool ok(int a, int b) {
    a = primes[a];
    b = primes[b];
    return isPrime(junt(a,b)) and isPrime(junt(b,a));
}

int main() {
    ios_base::sync_with_stdio(false);
    init();

    for(int i = 1; i < primes.size(); i++)
        for(int j = i+1; j < primes.size(); j++)
            if(ok(i,j))
                for(int k = j+1; k < primes.size(); k++)
                    if(ok(j,k) and ok(i,k))
                        for(int p = k+1; p < primes.size(); p++)
                            if(ok(k,p) and ok(j,p) and ok(i,p))
                                for(int q = p+1; q < primes.size(); q++)
                                    if(ok(p,q) and ok(k,q) and ok(j,q) and ok(i,q)) {
                                        print(i,j,k,p,q);
                                    }


    return 0;
}

