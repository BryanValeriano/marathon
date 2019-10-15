#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define loop(x) for(int i = 0; i < x; i++)
#define each(x, xs) for(auto &x : xs)
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef tuple<ll,ll,ll,char> node;
typedef vector<node> vn;

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vn bag;
set<int> v;

ll next(int pos, ll i, ll j, ll a) {
    ll l = j;
    ll r = 1e5 + 10;
    ll ans = r;

    while(l <= r) {
        ll mid = (l+r) >> 1;
        if(i + mid*a > pos) ans = mid, r = mid-1;
        else l = mid+1;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    int q; cin >> q;
    int n = s.size();

    while(q--) {
        int a,b,c;
        char d;
        cin >> a >> b >> c >> d;
        bag.eb(a,b,c,d);
    }

    for(int i = 1; i <= n; i++) v.insert(i);

    while(bag.size() and v.size()) {
        ll i,a,k;
        char d;
        tie(i,a,k,d) = bag.back();
        bag.pop_back();

        vector<int> del;
        ll j = 0;

        auto it = v.lower_bound(i + j*a);

        while(it != v.end() and j <= k) {
            int f = -1;
            if(*it == i + j*a) s[i + j*a -1] = d, del.pb(i + j*a), f = 0;
            j = next(*it + f,i,j,a);
            it = v.lower_bound(i + j*a);
        }

        for(auto ok : del) v.erase(ok);
    }

    cout << s << endl;

    return 0;
}
