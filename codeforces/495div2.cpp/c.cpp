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
map<int,int> track;
const int T = 1e5 + 10;
int v[T];
bool vis[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        track[v[i]]++;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        track[v[i]]--;
        if(track[v[i]] == 0) track.erase(v[i]);
        if(vis[v[i]]) continue;
        ans += track.size();
        vis[v[i]] = true;
    }
    cout << ans << endl;
    

    return 0;
}

