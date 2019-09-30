#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 4e5 + 4;
int v[T];
int acum[T];
vector<int> ve;
map<int,int> id;
int n,w,k;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> w;
    w *= 8;
    k = w/n;
    k = pow(2,k);
    

    for(int i = 0; i < n; i++) { cin >> v[i]; ve.pb(v[i]); }
    sort(ve.begin(), ve.end());
    ve.resize(unique(ve.begin(),ve.end()) - ve.begin());
    for(int i = 0; i < (int)ve.size(); i++) id[ve[i]] = i+1;
    for(int i = 0; i < n; i++) acum[id[v[i]]]++;
    for(int i = 1; i <= ve.size(); i++) acum[i] += acum[i-1];

    int best = 0; 
    for(int i = 1; i+k-1 <= ve.size(); i++) best = max(best, acum[i+k-1]-acum[i-1]);
    cout << n-best << endl;

    return 0;
}

