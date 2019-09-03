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

const int T = 1e7 + 10;
bitset<T> crivo;
vector<int> primes;

void init() {
    for(int i = 2; i < T; i++) 
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
}

int main() {
    init();
    int x;

    while(~scanf("%d\n", &x)) {
        int at = 8;
        int ans[4] = {2,2,2,2};
        for(int i = 0; i < 4; i++) {
            auto l = lower_bound(primes.begin(), primes.end(), x-at+2);
            while(l == primes.end() or (*l + at-2 > x and l != primes.begin())) l--;
            at += *l - 2;
            ans[i] = *l;
        }
        if(at == x) printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]); 
        else printf("Impossible.\n");
    }

    return 0;
}

