#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 105;
ll t[T];
ll l[T];
ll r[T];
ll n;
ll ini;

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> ini;
        for(int i = 0; i < n; i++)
            cin >> t[i] >> l[i] >> r[i];

        ll mini = INF;
        ll maxi = 0;
        bool f = 1;

        for(int i = n-2; i >= 0; i--) {
            ll deltaT = t[i+1] - t[i];
            ll mini = l[i+1] - deltaT;
            ll maxi = r[i+1] + deltaT;
            l[i] = max(l[i],mini);
            r[i] = min(r[i],maxi);
            if(l[i] > r[i]) f = 0;
        }

        f &= (l[0] <= r[0]);
        ll iniL = ini-t[0];
        ll iniR = ini+t[0];

        f &= (max(r[0],iniR) - min(l[0],iniL)+1 < r[0]-l[0]+1 + iniR-iniL+1);
        cout << (f? "YES" : "NO") << endl;

    }
    return 0;
}

