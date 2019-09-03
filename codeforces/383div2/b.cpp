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
const int T = 1e7;
ll row[T];
ll row2[T];

int main() {
    ios::sync_with_stdio(false);
    ll n, x; cin >> n >> x;
    ll aux;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        row[aux]++;
        row2[aux^x]++;
    }
    ll ans = 0;
    if(x != 0) {
        for(int i = 1; i <= T; i++) {
            if(row[i] > 0) {
                ans += (1LL * (row2[i] * row2[i^x]));
                row[i^x] = 0;
            }
        }
    } else {
        for(int i = 1; i <= T; i++)
            if(row[i] > 1) ans += (1LL *(row[i] * (row[i]-1LL))/2LL);
    }
    cout << ans << endl;

    return 0;
}

