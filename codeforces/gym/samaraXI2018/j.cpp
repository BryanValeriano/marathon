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
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int x;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> x;
        v[x]++;
        if(v[x] and !(v[x] % 2)) ans++;
    }
    cout << ans/2 << endl;

    return 0;
}

