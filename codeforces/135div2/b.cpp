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

ll n,k;
ll lim = LLONG_MAX;

bool f(ll x, int c) {
    string s = to_string(x);
    return (s[s.size() - c] != '9');
}

ll best(ll x) {
    ll casa = 10;
    ll passo = 1;
    ll best = x;

    while(1) {
        while(x > 0 and f(x,log10(casa))) x -= passo; 

        if(x  > 0 and n-x <= k) best = x;
        else break;

        if(lim/casa <= 10) break;

        casa *= 10;
        passo *= 10;
    }

    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k; 
    cout << best(n) << endl; 
    return 0;
}

