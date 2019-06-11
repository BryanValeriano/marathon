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

const int T = 2e5 + 5;
ll v[T];
ll s[T];
ll n,k;


int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> v[i];
        sort(v, v+n);
        cout << ((v[k] - v[0]) >> 1) << endl;
   }


    return 0;
}

