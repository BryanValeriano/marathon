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

const int T = 1e6 + 5;
const ll LIM = 2e18;
bitset<T> crivo;
vector<ll> primes;

int qtd[T];
vector<int> v;
vector<int> ve;

void init() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

void decop(int x) {
    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++) {
        int q = 0;

        while(x % primes[i] == 0) {
            x /= primes[i];
            q++;
        }

        qtd[primes[i]] = max(qtd[primes[i]],q);
    }

    if(x > 1) qtd[x] = max(qtd[x], 1);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    init();
    int tc; cin >> tc;

    while(tc--) {
        int n; cin >> n;
        v.clear(), ve.clear();

        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            decop(x);
            v.pb(x);
        }
        
        ll ans = 1;
        ll corn = 0;
        ll numCorn = 0;
        bool f = 0;

        for(ll i = 0; i < T; i++) {
            if(qtd[i] > 0) {
                corn++;
                numCorn = i;
                while(qtd[i] > 0) {
                    if(LIM/i < ans) f = 1; 
                    ans *= i;
                    qtd[i]--;
                }
            }
        }

        if(f) {
            cout << -1 << endl;
            continue;
        }

        if(corn == 1) ans *= numCorn;

        for(int i = 2; i < ans and i <= 1e6; i++) if(ans%i == 0) ve.pb(i);
        sort(v.begin(), v.end());
        
        //cout << ans << endl;
        //for(auto x : ve) cout << x << endl;

        cout << (ve == v? ans : -1) << endl; 
    }
    
    return 0;
}

