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
    int tc; cin >> tc;
    int s = 0;
    while(tc--) {
        int n; cin >> n;
        vector<int> ve;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            ve.pb(x);
        }

        sort(ve.begin(),ve.end());
        deque<int> v;
        deque<int> a;

        v.pb(ve[n-1]);
        a.pb(ve[0]);

        int l = 0;
        int r = n-2;
        int cont = 0;
        ll ans = 0;
        ll ans2 = 0;

        while(l <= r) {
            if(cont & 1) {
                v.pb(ve[r--]);
                if(l <= r) v.push_front(ve[r--]);
            } else {
                v.pb(ve[l++]);
                if(l <= r) v.push_front(ve[l++]);
            }
            cont++;
        }

        l = 1;
        r = n-1;
        cont = 1;

        while(l <= r) {
            if(cont & 1) {
                a.pb(ve[r--]);
                if(l <= r) a.push_front(ve[r--]);
            } else {
                a.pb(ve[l++]);
                if(l <= r) a.push_front(ve[l++]);
            }
            cont++;
        }


        for(int i = 1; i < n; i++) {
            ans += abs(v[i] - v[i-1]);
            ans2 += abs(a[i] - a[i-1]);
        }

        cout << "Case " << ++s << ": " << max(ans,ans2) << endl;
    }
    return 0;
}

