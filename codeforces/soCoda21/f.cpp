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
const int T = 3e5 + 4;
int ans[T];
set<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) v.insert(i);

    while(m--) {
        int l,r,x;
        cin >> l >> r >> x;
        vector<int> del;
        for(auto i = v.lower_bound(l); i != v.end() and *i <= r; ++i) {
            if(*i == x) continue;
            del.pb(*i);
            ans[*i] = x;
        }
        for(auto i : del) v.erase(i);
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

