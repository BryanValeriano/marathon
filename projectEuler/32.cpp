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

int dig(ll x) {
    ll a = 0;
    while(x) {
        x /= 10;
        a++;
    }
    return a;
}

bool check(ll i, ll j) {
    return (dig(i) + dig(j) + dig(i*j) >= 9);
}

int bin(ll x) {
    ll l = 1;
    ll r = 1e8;
    ll ans = 0;

    while(l <= r) {
        ll mid = (l+r) >> 1;
        if(check(x,mid)) ans = mid, r = mid-1;
        else l = mid+1;
    }

    return (int)ans;
}

bool ok(int i, int j) {
    int x = i*j;
    set<int> sz;

    while(x) {
        if(x%10) sz.insert(x%10);
        x /= 10;
    }

    while(i) {
        if(i%10) sz.insert(i%10);
        i /= 10;
    }

    while(j) {
        if(j%10) sz.insert(j%10);
        j /= 10;
    }

    return (sz.size() == 9);
}

set<int> ans;

int main() {
    ios_base::sync_with_stdio(false);

    for(int i = 2; i < 100; i++) {
        int j = bin(i);
        while(1) {
            int x = (dig(i) + dig(j) + dig(i*j));
            if(x > 9) break;
            if(ok(i,j)) {
                ans.insert(i*j);
                cout << i << " " << j << " " << i*j << endl;
            }
            j++;
        }
    }

    ll x = 0;
    for(auto y : ans) x += y;
    cout << x << endl;

    return 0;
}

