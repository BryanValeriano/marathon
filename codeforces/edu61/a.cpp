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
    ll v[4];
    cin >> v[0] >> v[1] >> v[2] >> v[3];
    ll abre = 2*v[0];
    ll fecha = 2*v[3];
    if(abre == fecha) {
        if(v[2] != 0 and v[0] == 0) cout << 0 << endl;
        else cout << 1 << endl;
    } else cout << 0 << endl;
    return 0;
}

