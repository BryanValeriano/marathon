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

vector<string> v;
int n;

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        sort(s.begin(), s.end());
        v.pb(s);
    }

    sort(v.begin(), v.end());
    v.pb("$");

    ll l = 0;
    ll r = 0;
    ll ans = 0;

    while(l < n) {
        while(v[l] == v[r]) r++;
        ll ok = r-l;
        ans += (ok*(ok-1))/2;
        l = r;
    }

    cout << ans << endl;

    return 0;
}

