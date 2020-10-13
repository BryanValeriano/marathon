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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

ll check(ll x) {
    ll ans = 1;
    for(int i = 0; i < 10; i++) ans *= x;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    string z = "codeforces";
    ll k; cin >> k;
    ll l = 1;
    ll ans = 1;
    ll r = 60;

    while(l <= r) {
        ll mid = (l+r)>>1;
        if(check(mid) > k) r = mid-1;
        else l = mid+1, ans = mid;
    }

    ll x = check(ans);
    ll rest = k-x;
    ll qtd = 0;

    while(k-x > 0) {
        x /= ans;
        x *= (ans+1);
        qtd++;
    }


    for(int i = 0; i < 10; i++)
        for(int j = 0; j < ans+(i<qtd); j++)
            cout << z[i];

    cout << endl;
    return 0;
}

