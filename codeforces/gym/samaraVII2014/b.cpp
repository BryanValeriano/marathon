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

const int T = 1e5 + 5;
ii v[T];

int main() {
    ios::sync_with_stdio(false);
    int n, x; cin >> n;
    ll sum = 0;

    for(int i = 0 ; i < n; i++) cin >> v[i].fi; 
    for(int i = 0 ; i < n; i++) cin >> v[i].se; 
    
    sort(v, v+n);

    for(int i = 0; i < n; i++) {
        sum += v[i].se;
        if(v[i].fi <= sum) { cout << "Redemption" << endl; return 0; }
    }
    
    cout << "Dire victory" << endl;

    return 0;
}
