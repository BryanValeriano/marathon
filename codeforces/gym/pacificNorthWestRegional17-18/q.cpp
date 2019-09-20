#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

ll x;
ll tot;
ll sum;


bool check(ll y) {
    y = tot-y;
    y *= y-1;
    y >>= 1;
    y = sum - y;
    return (y >= x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> x;
    tot = x;
    x *= x-1;
    x >>= 1;
    sum = x;
    x >>= 1;
    if(sum&1) x++;

    ll l = 1;
    ll r = tot;

    while(l <= r) {
        ll mid = (l+r) >> 1;
        if(check(mid)) r = mid-1;
        else l = mid+1;
    }

    cout << l << endl;
    return 0;
}

