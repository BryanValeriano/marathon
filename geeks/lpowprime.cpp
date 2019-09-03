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

int lpow(int n, int p) {
    int x = 0;
    while(n) {
        n /= p;
        x += n;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    int tc,n,p; cin >> tc;
    while(tc--) {
        cin >> n >> p;
        cout << lpow(n,p) << endl;
    }
    return 0;
}

