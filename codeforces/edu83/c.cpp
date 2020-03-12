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
const int T = 32;
const ll LIM = 1e17;

int n;
ll k;
ll v[T];
ll a[T];
vector<ll> pot;
 
int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> k;
        pot.clear();
        for(int i = 0; i < n; i++) cin >> a[i], v[i] = 0;

        ll ini = 1;
        pot.pb(ini);
        while(LIM/k > ini) ini *= k, pot.pb(ini); 

        while(pot.size()) {
            ll at = pot.back();
            pot.pop_back();

            for(int i = 0; i < n; i++)
                if(v[i] + at <= a[i]) { v[i] += at; break; } 
        }
        
        bool ans = 1;
        for(int i = 0; i < n; i++) ans &= (v[i] == a[i]);
        cout << (ans? "YES" : "NO") << endl;
    }
    return 0;
}

