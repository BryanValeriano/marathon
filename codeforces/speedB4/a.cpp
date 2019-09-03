#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 20;
ll v[T];

int32_t main() {
    ios::sync_with_stdio(false);
    int maxtam = 0;
    int n; cin >> n;
    int x, y, z, k;

    for(int i = 0; i < 16; i++) v[i] = pow(4ll,i);
    
    while(n--) {
        cin >> x >> y;
        z = 0;

        while(v[z] < y) z++;

        maxtam = max(maxtam,x+ max(z,1ll));
    }

    cout << maxtam << endl;

    return 0;
}

