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
const int T = 1e5 + 10;
int v[T];
int ans[T];

int main() {
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    set<int>track;
    for(int i = n; i >= 1; i--) {
        track.insert(v[i]);
        ans[i] = track.size();
    }
    int aux;
    for(int i = 0; i < m; i++) {
        cin >> aux;
        cout << ans[aux] << endl;
    }
    return 0;
}

