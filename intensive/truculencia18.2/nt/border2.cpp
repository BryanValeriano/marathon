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

set<int> ans;

int main() {
    ios::sync_with_stdio(false);
    int n, k; cin >> n >> k;
    int x, gcd = 0;
    for(int i = 0; i < n; i++) cin >> x, gcd = __gcd(gcd,x);
    gcd = __gcd(gcd,k);
    
    for(int i = gcd; i <= k; i += gcd) ans.insert(i % k);

    cout << ans.size() << endl;
    for(auto z : ans) cout << z << " ";
    cout << endl;

    return 0;
}

