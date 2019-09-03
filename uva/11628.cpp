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

const int T = 1e4 + 2;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    while(n or m) {
        int tot = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                cin >> v[i];
            tot += v[i];
        }

        for(int i = 0; i < n; i++) {
            int gcd = (v[i]? __gcd(v[i],tot) : tot);
            if(v[i]) gcd = __gcd(v[i],tot);
            cout << (v[i]? v[i]/gcd : v[i]) << " / " << tot/gcd << '\n';
        }
        cin >> n >> m;
    }

    return 0;
}

