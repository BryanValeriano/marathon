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
    int gordura = 0;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x&1) {
            if(x > 0) {
                if(gordura) ans.pb(x/2), gordura--;
                else ans.pb(x/2 + 1), gordura++;
            } else {
                if(gordura) ans.pb(x/2 - 1), gordura--;
                else ans.pb(x/2), gordura++;
            }
        } else ans.pb(x/2);
    }

    for(auto x : ans) cout << x << endl;

    return 0;
}

