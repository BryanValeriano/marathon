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
const int T = 1e8+2;
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

int main() {
    ios_base::sync_with_stdio(false);
    init();
    string s; cin >> s;
    ll n = stoll(s);
    bool ans = true;

    for (ll x : primes) {
        if (x * x > n or !ans) break;
        if (n % x == 0) ans = false;
    }

    for (char& c : s) {
        if (c == '6') c = '9';
        else if (c == '9') c = '6';
        else if (c == '3' or c == '4' or c == '7') ans = false;
    }
    n = stoll(string(s.rbegin(), s.rend()));
    if (n == 1) ans = false;
    for (ll x : primes) {
        if (x * x > n or !ans) break;
        if (n % x == 0) ans = false;
    }

    cout << (ans ? "yes" : "no") << endl;
    return 0;
}

