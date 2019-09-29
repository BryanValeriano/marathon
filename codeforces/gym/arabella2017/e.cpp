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

const int T = 100;
int mid;
int t;
vector<int> primes = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,1 };
bitset<T> v;

bool bota(int x, int y) {
    for(int i = x; i <= y; i++) if(v[i]) return 0;
    for(int i = x; i <= y; i++) v[i] = 1;
    return 1;
}

void des(int x, int y) {
    for(int i = x; i <= y; i++) v[i] = 0;
}

bool solve(bool o) {
    bool x = !o;
    bool ok = 0;

    for(int i = 0; i < primes.size(); i++) {
        if(primes[i] > mid) { i = primes.size()-2; continue; }
        if(i + 1 == primes.size() and ok) break;


        for(int j = 0; j+primes[i]-1 < t; j++) {
            if(bota(j,j+primes[i]-1)) {
                x = (o? max(x,solve(!o)) : min(x,solve(!o)));
                des(j,j+primes[i]-1);
                ok = 1;
            }
        }
    }

    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 1; i <= 50; i++) {
        v.reset();
        mid = i/2 + (i&1); t = i;
        cout << solve(0) << endl;
    }

    return 0;
}

