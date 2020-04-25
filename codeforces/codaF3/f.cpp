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
const int T = 1e5 + 2;
int v[T];
int n,k;

bool check(int sz) {
    multiset<int> bag;
    for(int i = 0; i < sz; i++) bag.insert(v[i]);
    if(*bag.rbegin() - *bag.begin() <= k) return 1;
    for(int i = sz; i < n; i++) {
        bag.erase(bag.find(v[i-sz]));
        bag.insert(v[i]);
        if(*bag.rbegin() - *bag.begin() <= k) return 1;
    }
    return 0;
}

void build(int sz) {
    multiset<int> bag;
    vector<ii> ans;
    for(int i = 0; i < sz; i++) bag.insert(v[i]);
    if(*bag.rbegin() - *bag.begin() <= k) ans.eb(1,sz);
    for(int i = sz; i < n; i++) {
        bag.erase(bag.find(v[i-sz]));
        bag.insert(v[i]);
        if(*bag.rbegin() - *bag.begin() <= k) ans.eb(i-sz+2,i+1);
    }
    cout << ans.size() << endl;
    for(auto x : ans) cout << x.fi << " " << x.se << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> v[i];
    int l = 1;
    int r = n;
    int ans = 1;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }

    cout << ans << " ";
    build(ans);

    return 0;
}

