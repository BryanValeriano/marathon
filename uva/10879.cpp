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

const int T = 1e5;
bitset<T> crivo;
vector<int> primes;

void init() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j+= i) crivo[j] = 1;
        }
    }
}

vector<int> decop(int x) {
    vector<int> v;
    for(int i = 0; i < primes.size() and primes[i] * primes[i] <= x; i++) {
        while(x % primes[i] == 0) v.pb(primes[i]), x /= primes[i];
    }
    if(x > 1) v.pb(x);
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    init();
    int n; cin >> n;
    int cont = 0;

    while(n--) {
        int x; cin >> x;
        vector<int> v = decop(x);

        int a = v[0],b = x/a,c = v[0]*v[1],d =x/c;
        cout << "Case #" << ++cont << ": " << x << " = " << a << " * " << b << " = "<< c << " * " << d << endl;
    }
    return 0;
}

