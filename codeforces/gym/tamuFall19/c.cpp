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
    int n,k; cin >> n >> k;
    set<int> ans;
    if(k) {
        ans.insert(n-k-1);
        ans.insert(1);
        int a = n/2;
        int b = n/2 + (n&1);
        ans.insert(a);
        ans.insert(b);
    } else ans.insert(n);
    cout << ans.size() << endl;
    for(auto x : ans) cout << x << " ";
    cout << endl;
    return 0;
}

