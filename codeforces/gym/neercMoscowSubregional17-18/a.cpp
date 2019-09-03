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
    ll n,k;
    cin >> n >> k;

    int ans = INF; 

    for(int i = 1; i < k; i++) {
        ll at = i;
        int tent = 1;

        while(at < n-(k-i)) {
            tent++;
            at += min(at, (n-at)/2LL);
        }

        ans = min(ans,tent);
    }

    cout << ans << endl;

    return 0;
}

