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
const ll INF = 1e9 + 100;

const int T = 1e5 + 10;
int pos[T];
int n, c;

bool can(ll x) {
    int at = 1;
    int iter = 0;
    int last = pos[0];
    while(at < c) {
        if(iter == n) return false; 
        if(pos[iter] - last >= x) last = pos[iter], at++;
        iter++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> c;
        for(int i = 0; i < n; i++) cin >> pos[i];
        sort(pos, pos+n);
        
        ll l = 0;
        ll r = INF;

        while(l <= r) {
            ll mid = (l+r) >> 1;
            if(can(mid)) l = mid+1;  
            else r = mid-1;
        }

        cout << r << endl;

    }
    return 0;
}

