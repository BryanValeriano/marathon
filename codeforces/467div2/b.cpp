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

const int T = 1e5 + 10;
bitset<T> crivo;
vector<ll> primes;

bool isP(int x) {
    for(int i = 0; i < primes.size(); i++) if(! (x % primes[i]) ) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int p,y;
    cin >> p >> y;
    int tent = y;
    
    for(ll i = 2; i <= p and i < T; i++)
        if(!crivo[i]) {
            primes.pb(i);
            for(ll j = i*i; j < T; j += i) crivo[j] = 1;
        }
    
    while(y > p) { 
        if(isP(y)) { cout << y << endl; return 0; }
        y--;
    }
    
    cout << -1 << endl;

    return 0;
}

