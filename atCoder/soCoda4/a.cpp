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
const ll INF = 1e18;
const double PI = acos(-1.0);
const int T = 3e5 + 3;
int v[T];
ll b[T],s[T];

multiset<int> bag;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    ll tmp = 0;
    for(int i = 0; i < 3*n; i++) {
        cin >> v[i];
        tmp += v[i];
        bag.insert(v[i]);
        if(bag.size() > n) {
            ll at = *bag.begin();
            tmp -= at;
            bag.erase(bag.find(at));
        }
        b[i] = tmp;
    }

    tmp = 0;
    bag.clear();

    for(int i = 3*n-1; i >= 0; i--) {
        tmp += v[i];
        bag.insert(v[i]);
        if(bag.size() > n) {
            ll at = *bag.rbegin();
            tmp -= at;
            bag.erase(bag.find(at));
        }
        s[i] = tmp;
    }

    ll ans = -1e18;

    for(int i = n-1; i < 2*n; i++)
        ans = max(ans, b[i] - s[i+1]);
    cout << ans << endl;
    return 0;
}

