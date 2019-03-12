#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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

const int T = 2e3 + 3;
int v[T];
tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> s;

int main() {
    ios::sync_with_stdio(false);
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> v[i];
    int j = 1;
    int ans = 0;
    int a,b,x;
    for(int i = 0; i < q; i++) {
        cin >> a >> b >> x;
        x--;
        s.clear();
        for(int i = a; i <= b; i++) s.insert(v[i]);
        cout << *(s.find_by_order(x)) << endl;
    }
    return 0;
}

