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

const int T = 3e5 + 3;

vii degrau;
int v[T];
bool ok[T];
int n, k;

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        if(i > 1) degrau.eb(v[i]-v[i-1],i);
    }

    sort(degrau.begin(), degrau.end(), greater<ii>());
    for(int i = 0; i < k-1; i++) ok[degrau[i].se] = 1;

    ll ans = 0;
    int mini = INF;
    int maxi = 0;

    for(int i = 1; i <= n; i++) {
        if(ok[i]) {
            ans += maxi-mini;
            mini = INF;
            maxi = 0;
        }
        maxi = max(maxi,v[i]);
        mini = min(mini,v[i]);
    }

    ans += maxi-mini;
    
    cout << ans << endl;
    return 0;
}

