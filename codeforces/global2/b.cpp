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

const int T = 1e3 + 3;
int v[T];
int n,h;

bool check(int x) {

    ll ve[x];
    for(int i = 0; i < x; i++) ve[i] = v[i+1];
    sort(ve, ve+x, greater<ll>());
    
    ll t = 0;

    for(int i = 0; i < x; i++) 
        if(!(i&1)) t += ve[i];


    return t <= h;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> h;

    for(int i = 1; i <= n; i++) cin >> v[i];
    
    int l = 1;
    int r = n;
    int ans = 0;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(mid)) ans = mid, l = mid+1;
        else r = mid-1;
    }

    cout << ans << endl;

    return 0;
}

