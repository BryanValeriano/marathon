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

const int T = 1e5 + 3;
ll v[T];
 
int main() {
    ios_base::sync_with_stdio(false);
    ll n,k,q;
    cin >> n >> k >> q;

    for(int i = 0; i < q; i++) {
        int x; cin >> x;
        v[x]++;
    }

    for(int i = 1; i <= n; i++) 
        cout << (k - q + v[i] > 0? "Yes" : "No") << endl;
    
    return 0;
}

