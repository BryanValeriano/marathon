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
bitset<T> check;
vector<int> primes;

void crivo() {
    for(int i = 2; i < T; i++) {
        if(!check[i]) {
            primes.pb(i);
            for(int j = i + i; j < T; j += i)
                check.set(j,true);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    crivo();
    int x; cin >> x;
    int i = 0;
    while(primes[i] <= x and i < primes.size()) 
        cout << primes[i++] << " ";
    cout << endl; 
    return 0;
}

