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

const int T = 1e5 + 5;
const int LIM = T;

int n,k;
ll freq[T];
int viz[T];
vector<int> primes;
bitset<T> crivo;

void init() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j+= i) crivo[j] = 1;
        }
    }
}

bool can(ll x, ll y) {
    ll ori = x;
    y--;
    while(y) {
        if(LIM/ori < x) return 0;
        x *= ori;
        y--;
    }
    return 1;
}

void decop(int x) {
    vector<int> ans;
    vector<int> v;
    bool flag = 0;

    for(int i = 0; i < primes.size() and primes[i]*primes[i] <= x; i++) {
        if(x % primes[i] == 0) {
            int qtd = 0;
            while(x % primes[i] == 0) qtd++, x /= primes[i];
            qtd %= k;
            if(qtd) {
                ans.pb(pow(primes[i],qtd));
                int z = k-qtd;
                if(z) {
                    if(can(primes[i],z)) v.pb(pow(primes[i],z));
                    else flag = 1;
                }
            }
        }
    }

    if(x > 1) {
        ans.pb(x);
        if(can(x,k-1)) v.pb(pow(x,k-1));
        else flag = -1;
    }

    int a = 0, b = 0;
    for(int i = 1; i < ans.size(); i++) ans[i] *= ans[i-1];
    if(ans.size()) a = ans.back();
    freq[a]++;

    if(!flag) {
        for(int i = 1; i < v.size(); i++) {
            if(LIM/v[i-1] < v[i]) { viz[a] = -1; return; }
            v[i] *= v[i-1];
        }
        if(v.size()) b = v.back();

        viz[a] = b; return;
    }

    viz[a] = -1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    init();

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        decop(x);
    }

    ll ans = 0; 

    for(int i = 0; i < T; i++) {
        if(freq[i]) {
            if(viz[i] == i) ans += (freq[i] * (freq[i]-1)) >> 1;
            else if(viz[i] > i) ans += freq[i] * freq[viz[i]];
        }
    }
   
    cout << ans << endl;
    return 0;
}

