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

const int T = 1e7 + 5;
bitset<T> crivo;
vector<ll> primes;
int ok;

void pre() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            if(primes.size() == ok) { cout << i << endl; exit(0); }
            for(int j = i+i; j < T; j+= i) crivo[j] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ok;
    pre();
    return 0;
}

