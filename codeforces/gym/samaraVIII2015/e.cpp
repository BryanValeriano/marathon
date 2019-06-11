#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<double,ll> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 3;

double size[T];
double last[2][T];
int ans[T];
set<ii> bag;
 
int main() {
    ios_base::sync_with_stdio(false);
    ll n, k, x;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> x;
        if(i < k) {
            bag.insert(ii(x,i));
            ans[i] = i;
            size[i]++;
            last[1][i] = x;
        } else {
            ii at = *bag.begin();
            bag.erase(bag.begin());
            ans[i] = at.se;
            last[0][at.se] = last[1][at.se];
            last[1][at.se] = x;
            size[at.se]++;
            bag.insert(ii(size[at.se] * ((last[0][at.se] + last[1][at.se])/2), at.se));
        }
    }

    for(int i = 0; i < n; i++) cout << ans[i]+1 << " "; 
    cout << endl;
    
    return 0;
}

