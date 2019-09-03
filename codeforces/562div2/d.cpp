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

const int T = 3e5 + 3;
const int N = T/2;
bitset<N> crivo;
vector<int> primes;

void pre() {
    for(int i = 2; i < N; i++) {
        if(crivo[i]) continue;
        primes.pb(i);
        for(int j = i+i; j < N; j += i) crivo[j] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    pre();
    cout << primes.size() << endl;

    return 0;
}

