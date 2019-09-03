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

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    ll aux;
    ll ans = 0;
    ll last = 0;
    ll lastAns = 0;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        aux += last;
        last = aux;
        ans = aux/m;
        cout << ans - lastAns << " ";
        lastAns = ans;
    }
    cout << endl;
    return 0;
}

