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
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
 
int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<ll> a(m);
    ll r = 0, x;
    bool p = true;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < 2 * m;j++) {
            cin >> x;
            if (j & 1) r += x;
            else a[j >> 1] += x;
        }
        p = p & (r == 0);
    }
    for (int i = 0;i < m;i++) p = p & (a[i] == 0);
    cout << (p ? "Yes" : "No") << endl;
    
    return 0;
}

