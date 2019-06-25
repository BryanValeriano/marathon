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
    ios_base::sync_with_stdio(false);

    int n;
    unsigned long long ans = 0, x;
    int id = 0;
    cin >> n;
    for (int i = 0;i < n;i++) {
        cin >> x;
        ans += (x & 127) << id;
        id += 7;
        if (!(x & 128)) {
            if (ans & 1) cout << - (ll)(ans / 2) - 1 << endl;
            else cout << ans / 2 << endl;
            ans = 0;
            id = 0;
        }
    }
    return 0;
}

