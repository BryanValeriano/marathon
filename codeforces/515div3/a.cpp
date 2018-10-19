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
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) {
        int L, v, l, r; cin >> L >> v >> l >> r;
        int tot = L/v;
        int ret = 0;
        int sob = (r-l+1)%v;
        if(ret == 0 && sob == 0 && l % v == 0) ret++;
        //else if(sob == 0 && l%v == 0 && r%v == 0) ret++;
        else if(sob > 0) {
            for(int i = 1; i*v <= r; i++) 
                if(i*v >= l && i*v <= r) { ret++; break; }
        }
        cout << tot - ret << endl;
    }
    return 0;
}

