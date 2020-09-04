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
const int T = 1e7;
vector<ll> primes;
bitset<T> crivo;

void pre() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    pre();
    int n; cin >> n;
    ll last = 1;

    for(ll i = 2; i <= n; i++) {
        if((last+1)*(2ll) <= i)last++;
        cout << last << " ";
    }
    cout << endl;

    return 0;
}

