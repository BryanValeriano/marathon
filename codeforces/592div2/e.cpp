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
ll n,k;
vector<ll> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.pb(x);
    }

    sort(v.begin(), v.end());

    ll mini = 1;
    ll maxi = 1;
    int l = 0;
    int r = n-1;
    ll a = v[l];
    ll b = v[r];

    while(l < r and k) {
        if(mini <= maxi) {
            ll dist = v[l+1] - v[l];
            if(dist*mini <= k) {
                l++;
                a = v[l];
                k -= dist*mini;
                mini++;
            } else {
                a += (k/mini);
                break;
            }
        } else {
            ll dist = v[r] - v[r-1];
            if(dist*maxi <= k) {
                r--;
                b = v[r];
                k -= dist*maxi;
                maxi++;
            } else {
                b -= (k/maxi);
                break;
            }
        }
    }


    cout << b-a << endl;

    return 0;
}

