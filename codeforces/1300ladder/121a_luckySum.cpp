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
const ll LIM = 1e10;
set<ll>track;

void build(ll x) {
    if(x > LIM) return;
    track.insert(x);
    build((x*10) + 4);
    build((x*10) + 7);
}

int main() {
    ios::sync_with_stdio(false);
    build(4);
    build(7);
    ll l, r;
    cin >> l >> r;
    ll ans = 0;
    auto it = track.lower_bound(l); 
    while(l <= r) {
        ans += (*it * ((min(*it,r) - l)+1));
        l = *it + 1;
        it++;
    }
    cout << ans << endl;
    return 0;
}

