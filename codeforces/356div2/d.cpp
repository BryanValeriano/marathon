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

const ll T = 1e5;

int m;
bool crivo[T];
vector<int> primes;

void pre() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            primes.pb(i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    pre();
    cin >> m;
    int ans = min(7,m);

    return 0;
}

