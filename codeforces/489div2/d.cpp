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

const int T = 2e5 + 10;
ll v[T];
int uns[T];

int main() {
    ios::sync_with_stdio(false);
    int n;
    ll k;
    ll lim = 1e18;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        if(v[i] == 1) uns[i] = 1;
    }

    for(int i = n; i >= 1; i--) 
        if(uns[i]) uns[i] += uns[i+1];

    ll ans = 0; 

    for(int i = 1; i <= n; i++) {
        ll prod = 1;
        ll sum = 0;
        int goods = 0;
        int j = i;
        while(goods < 60 and j <= n) {
            if(v[j] != 1) {
                goods++;
                if(lim/v[j] <= prod) break;
                prod *= v[j];
                sum += v[j];
                if(sum*k == prod) ans++; 
                j++;
            } else {
                ll dist = (prod/k) - sum;
                if(uns[j] >= dist and dist > 0 and (sum+dist)*k == prod) ans++;
                sum += uns[j];
                j += uns[j];
            }
        }
    }

    cout << ans << endl;

    return 0;
}

