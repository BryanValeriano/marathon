#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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
    int n; cin >> n;
    vector<int> ans;
    for(int i = 1; i <= n; i+=2) ans.pb(i);
    if(ans.back() != n) ans.pb(n);
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;
    return 0;
}

