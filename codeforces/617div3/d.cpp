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
    int n,a,b,k;
    int ans = 0;
    cin >> n >> a >> b >> k;
    vector<int> v;

    while(n--) {
        int hi; cin >> hi;
        hi -= (a+b) * (hi/(a+b));

        if(!hi) hi += b;
        else hi -= a;

        if(hi <= 0) ans++;
        else v.pb(hi/a + (hi%a? 1 : 0));
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++) {
        if(k - v[i] < 0) break;
        k -= v[i];
        ans++;
    }

    cout << ans << endl;

    return 0;
}

