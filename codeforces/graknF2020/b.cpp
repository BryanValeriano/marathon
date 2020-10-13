#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n,k; cin >> n >> k;
        set<int> bag;
        while(n--) {
            int x; cin >> x;
            bag.insert(x);
        }
        n = bag.size();
        if(k==1) cout << (n==1?1:-1) << endl;
        else {
            int ans = 1;
            n = max(0,n-k);
            k--;
            ans += (n/k + (n%k?1:0));
            cout << ans << endl;
        }
    }
    return 0;
}

