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

const int T = 1e5;
bitset<T> crivo;
vector<ll> primes;

void init() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

void solve(int x) {
    cout << x << " = ";
    bool ok = 0;
    if(x < 0) { cout << -1, ok = 1; }
    x = abs(x);

    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++) {
        while(x % primes[i] == 0) {
            if(ok) cout << " x " << primes[i];
            else { cout << primes[i], ok = 1; }
            x /= primes[i];
        }
    }

    if(x != 1) { 
        if(ok) cout << " x " << x; 
        else cout << x;
    }
    cout << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    init();
    int x; cin >> x;
    while(x != 0) { solve(x), cin >> x; }
    return 0;
}

