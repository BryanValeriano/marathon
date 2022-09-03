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
    int n,m;
    int ans = INF;
    cin >> n >> m;
    while(m--) {
        int l,r; cin >> l >> r;
        ans = min(ans, r-l+1);
    }
    cout << ans << endl;
    for(int i = 0; i < n; i++) cout << i%ans << " ";
    cout << endl;
    return 0;
}

