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
const int T = 1e6;
int segs[T];
int ans[T];
vector<ii> v;
vector<int> ve;
map<int,int> id;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int a, b;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.eb(a,b+1);
        ve.pb(a); ve.pb(b+1);
    }

    sort(ve.begin(), ve.end());
    ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
    for(int i = 0; i < ve.size(); i++) id[ve[i]] = i;
    for(int i = 0; i < n; i++) {
        segs[id[v[i].fi]]++;
        segs[id[v[i].se]]--;
    }

    for(int i = 1; i < T; i++)
        segs[i] += segs[i-1];
    for(int i = 0; i < T; i++) 
        ans[segs[i]]++;
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
    for(int i = 0; i < 20; i++) cout << segs[i] << " ";
    cout << endl;


    return 0;
}

