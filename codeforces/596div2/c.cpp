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
const ll LIM = 1e9 + 1e5;
int n,p;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> p;
    int ans = 1;
    n -= p;

    while(n >= ans and ans < 32) {
        if(__builtin_popcount(n) <= ans) {
            cout << ans << endl;
            return 0;
        }
        ans++;
        n -= p;
    }    

    cout << -1 << endl;
    return 0;
}

