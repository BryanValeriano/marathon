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
    int n, g;
    cin >> n >> g;
    vector<int>v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    int s = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        s += v[i];
        ans++;
        if(s >= g) break;
    }
    cout << ans << endl;

    return 0;
}

