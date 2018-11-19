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
ll v[T];
vector<int> ve;
ll ans[T];
ll menos[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) { 
        cin >> v[i];
        ve.pb(v[i]);
    }
    sort(ve.begin(), ve.end());
    ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
    map<int,int>ind;
    for(int i = 1; i <= ve.size(); i++) 
        ind[ve[i-1]] = i;
    for(int i = 0; i < n; i++) 
        ans[i] = (ind[v[i]] <= 5? ind[v[i]] : 5);
    

    for(int i = 0; i < n; i++) 
        cout << ans[i] << " ";
    cout << endl;


    return 0;
}

