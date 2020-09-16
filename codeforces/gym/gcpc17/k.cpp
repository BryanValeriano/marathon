#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<ll,string> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    ll n,d,k;
    cin >> n >> d >> k;
    vii v;
    for(int i = 0; i < n; i++) {
        string s; int x;
        cin >> s >> x;
        v.eb(x,s);
    }
    sort(v.begin(),v.end(), greater<ii>());
    vector<string> ans;
    ll sum = 0;

    for(int i = 0; i < k and sum < d; i++) {
        sum += v[i].fi;
        ans.pb(v[i].se);
    }
    if(sum >= d) {
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << ", YOU ARE FIRED!\n";
    } else cout << "impossible\n";
    return 0;
}

