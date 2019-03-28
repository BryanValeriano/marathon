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

const int T = 3e6;
int v[T];
ll compress[T+20];
vector<int> ve;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        v[i] = x;
        for(int j = max(0,x-5); j <= x+5; j++) ve.pb(j);
    }

    sort(ve.begin(), ve.end());
    ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
    map<int,int> id;
    for(int i = 0; i < ve.size(); i++) id[ve[i]] = i+1;

    for(int i = 0; i < n; i++) compress[id[v[i]]]++;
    for(int i = 1; i < T; i++) compress[i] += compress[i-1];

    ll ans = 0;
    for(int i = 6; i <= T; i++) {
        int low = i-5;
        int high = i;
        ll score = compress[high] - compress[low-1];
        ans = max(ans, score);
    }

    cout << ans << endl;
    

    return 0;
}

