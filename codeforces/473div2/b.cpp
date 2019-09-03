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
    int n, k, m; cin >> n >> k >> m;
    map<string, int> v;
    vector<int>cust;
    string tmp;
    int aux;
    for(int i = 0; i < n; i++) {
        cin >> tmp;
        v[tmp] = i;
    }
    for(int i = 0; i < n; i++) {
        cin >> aux;
        cust.pb(aux);
    }
    int grup;
    int mini;
    vector<int> track;
    for(int i = 0; i < k; i++) {
        cin >> grup;
        mini = INF;
        for(int j = 0; j < grup; j++) {
            cin >> aux; 
            track.pb(aux-1);
            mini = min(mini, cust[aux-1]);
        }
        for(int j = 0; j < grup; j++) 
            cust[track[j]] = mini;
        track.clear();
    }
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        ans += cust[v[tmp]];
    }
    cout << ans << endl;



    return 0;
}

