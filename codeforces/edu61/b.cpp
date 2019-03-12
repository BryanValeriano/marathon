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

const int T = 3e5 + 10;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n, m; cin >> n;
    ll sum = 0;
    for(int i = 1; i <= n; i++) cin >> v[i], sum += v[i];
    sort(v+1, v+n+1, greater<int>());
    cin >> m;
    int tent;
    for(int i = 0; i < m; i++) {
        cin >> tent;
       cout << sum -v[tent] << endl;
    }
    return 0;
}

