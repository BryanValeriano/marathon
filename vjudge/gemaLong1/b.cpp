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
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    ll n,k,m;
    while(tc--) {
        cin >> n >> k >> m;
        ll qtd = n/k;
        ll mini = n%k;
        if(mini) {
            qtd++;
            mini = (k-mini)/2 + 1;
            cout << qtd << " ";
            mini %= m; qtd %= m;
            cout << (mini*qtd)%m << endl;
        } else {
            cout << qtd << " " << 1 << endl;
        }
    }
    return 0;
}

