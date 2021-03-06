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

vii v;
vector<int> ans;

int main() {
    ios::sync_with_stdio(false);
    int sum,lim;
    cin >> sum >> lim;

    for(int i = 1; i <= lim; i++) v.eb(i&(-i), i);
    sort(v.begin(), v.end(), greater<ii>());

    int at = 0;
    for(int i = 0; i < v.size(); i++) 
        if(at + v[i].fi <= sum) at += v[i].fi, ans.pb(v[i].se);

    if(at == sum) {
        cout << ans.size() << endl;
        for(auto x : ans) cout << x << " ";
        cout << endl;
    } else cout << -1 << endl;

    return 0;
}

