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
const int T = 2e5 + 10;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int z = 0;
    int u = 0;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        if(v[i] == 1) u++;
        else z++;
    }
    for(int i = 1; i <= n; i++) {
        if(v[i] == 1) u--;
        else z--;
        if(z == 0 or u == 0) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}

