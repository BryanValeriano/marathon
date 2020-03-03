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

const int T = 5e5 + 5;
ll v[T];
unordered_map<ll,vector<int>> bag;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i-1];
        bag[v[i]].pb(i);
    }

    for(unordered_map<ll,vector<int>>::iterator it = bag.begin(); it != bag.end(); ++it)
        reverse(it->se.begin(),it->se.end());

    ll ans = 0;

    for(int i = 1; i < n-1; i++) {
        bag[v[i]].pop_back();
        if(bag[v[i]*2ll].size()) {
            int x = bag[v[i]*2ll].back();
            if(v[n]-v[x] == v[i]) ans += (ll)bag[v[i]*2ll].size() - (v[i]*2ll == v[n]);
        }
    }

    cout << ans << endl;

    return 0;
}

