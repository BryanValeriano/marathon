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
 
int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> v;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.pb(x);
    }

    sort(v.begin(), v.end()); 

    int ans = 0;
    int small = 0;

    for(auto x : v) {
        if(x-1 > small and x-1 > 0) x--;
        if(x == small) x++;
        if(x > small) ans++;
        small = max(small,x);
    }

    cout << ans << endl;
    
    return 0;
}

