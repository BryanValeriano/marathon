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

set<int> bag[2];
int n;
vii v;

ll getAns(int op) {
    ll ans = 0;
    if(op == 0) sort(v.begin(), v.end());
    else sort(v.rbegin(), v.rend());

    for(int i = 0; i < n; i++) {
        auto iter = bag[op].lower_bound(v[i].se);
        int h = (*iter)-1;
        int l = (*(--iter))+1;
        int low = min(v[i].se,l);
        int high = max(v[i].se,h);
        ans += (ll)(v[i].se-low+1)*(ll)(high-v[i].se+1)*(ll)v[i].fi;
        bag[op].insert(v[i].se);
    }

    bag[op].clear();
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin >> n;

    bag[0].insert(0);
    bag[0].insert(n+1);
    bag[1].insert(0);
    bag[1].insert(n+1);

    for(int i = 1; i <= n; i++) {
        cin >> x;
        v.eb(x,i);
    }

    ll small = getAns(0);
    ll big = getAns(1); 

    cout << big-small << endl;

    return 0;
}

