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

int main() {
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    if(n <= 2) cout << n+1 << endl;
    else {
        ll tam = 2;
        ll passo = 1;
        ll at = 3;
        while(tam < n) {
            if(!(at&1)) tam += passo;
            else tam += (++passo);
            at++;
        }
        cout << at << endl;
    }
    return 0;
}

