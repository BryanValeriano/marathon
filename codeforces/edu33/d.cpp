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

const int T = 1e5 + 10;
ll acum[T];
ll v[T];
ll n, k;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    vector<ll> ve;
    for(int i = 1; i <= n; i++) cin >> v[i], acum[i] = v[i];
    
    for(int i = 1; i <= n; i++) acum[i] += acum[i-1];
   
    ll maxi = acum[n];
    for(int i = n; i >= 1; i--) {
        if(v[i] != 0) maxi = max(maxi, acum[i]);
        else ve.pb(maxi);
    }

    ll ans1 = 0;
    ll bonus = 0;
    int iter = 0;
    reverse(ve.begin(), ve.end());

    for(int i = 1; i <= n; i++) { 
        if(v[i] == 0 and (acum[i] + bonus) < 0) { 
            ans1++;
            if(iter < ve.size() and (k - (ve[iter] - bonus)) > 0) bonus = (k - ve[iter]);  
            if(acum[i] + bonus < 0) { cout << -1 << endl; return 0; }
            iter++;
        }
        if(acum[i] + bonus > k) {
            cout << -1 << endl;
            return 0;
        }
    } 

    cout << ans1 << endl;
    return 0;
}

