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
const int T = 2e5 + 10;

map<int,int> in;
vector<int> v;


int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        in[x]++;
    }

    for(auto ok : in) v.pb(ok.se);
    sort(v.begin(),v.end());
    int best = 0;

    for(int base = 1; base <= n; base++) {
        int l = lower_bound(v.begin(),v.end(),base) - v.begin();
        if(l >= v.size()) continue;

        int ans = base;
        int j = base << 1;
        int r = lower_bound(v.begin()+l+1,v.end(),j) - v.begin();

        while(r < v.size()) {
            ans += j;
            j = j << 1;
            r = lower_bound(v.begin()+r+1,v.end(),j) - v.begin();
        }

        best = max(best,ans);
    }

    cout << best << endl;

    return 0;
}

