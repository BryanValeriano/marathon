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

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    int gol = 42;

    while(tc--) {
        int n; cin >> n;
        ll sum = 0;
        int ans = 0;
        queue<ll> at;

        while(n--) {
            ll x; cin >> x;
            sum += x;
            at.push(x);

            while(sum > gol) {
                sum -= at.front();
                at.pop();
            }

            if(sum == gol) {
                ans++, sum = 0;
                while(at.size()) at.pop();
            }
        }

        cout << ans << endl;

    }
    return 0;
}

