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
    int n; cin >> n;
    int at; cin >> at;

    int tot = 0;
    int a = at;
    int x;
    vector<int> ans;
    ans.pb(1);

    for(int i = 2; i <= n; i++) {
        cin >> x;
        if(at/2 >= x) a += x, ans.pb(i);
        else tot += x;
    }

    if(a <= tot) { cout << 0 << endl; return 0; }
    cout << ans.size() << endl;
    for(auto k : ans) cout << k << " ";
    cout << endl;

    return 0;
}

