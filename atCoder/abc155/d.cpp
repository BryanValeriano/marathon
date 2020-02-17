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

vector<ll> pos;
vector<ll> poss;
vector<ll> neg;
vector<ll> negg;
ll n,k;

bool check(ll x) {
    ll ans = 0;

    //neg neg
    //int tmp = 0;
    for(int i = 0; i < neg.size(); i++) {
        ll l = i+1;
        ll r = negg.size()-1;

        while(l <= r) {
            ll mid = (l+r) >> 1;
            if(negg[i] * negg[mid] > x) r = mid-1;
            else l = mid+1;
        }

        while(l > negg.size()-1) l--;
        while(l > i and negg[i]*negg[l] > x) l--;
        ans += max(0ll, l-i);
        //tmp += max(0ll,l-i);
    }

    //cout << "neg neg " << tmp << endl;
    //tmp = 0;


    //neg pos
    for(int i = 0; i < neg.size(); i++) {
        ll l = 0;
        ll r = poss.size()-1;

        while(l <= r) {
            ll mid = (l+r) >> 1;
            if(neg[i] * poss[mid] > x) r = mid-1;
            else l = mid+1;
        }

        while(l > poss.size()-1) l--;
        while(l >= 0 and neg[i]*poss[l] > x) l--;
        ans += max(0ll, l+1);
        //tmp += max(0ll,l+1);
    }
    //cout << "neg pos " << tmp << endl;
    //tmp = 0;

    //pos pos
    for(int i = 0; i < pos.size(); i++) {
        ll l = i+1;
        ll r = pos.size()-1;

        while(l <= r) {
            ll mid = (l+r) >> 1;
            if(pos[i] * pos[mid] > x) r = mid-1;
            else l = mid+1;
        }

        while(l > pos.size()-1) l--;
        while(l > i and pos[i]*pos[l] > x) l--;
        ans += max(0ll, l-i);
        //tmp += max(0ll, l-i);
    }

    //cout << "pos pos " << tmp << endl;
    //cout << x << " " << ans << " " << " " << k << " " << (ans >= k) << endl;

    return (ans >= k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        if(x >= 0) { pos.pb(x), poss.pb(x); }
        else { neg.pb(x), negg.pb(x); }
    }

    sort(pos.begin(), pos.end());

    sort(poss.begin(), poss.end());
    reverse(poss.begin(), poss.end());

    sort(neg.begin(), neg.end());

    sort(negg.begin(), negg.end());
    reverse(negg.begin(), negg.end());

    ll l = -1e18 + 5;
    ll r = 1e18 + 5;
    ll ans = 0;

    while(l <= r) {
        ll mid = (l+r) >> 1;
        if(check(mid)) ans = mid, r = mid-1;
        else l = mid+1;
    }

    cout << ans << endl;

    return 0;
}

