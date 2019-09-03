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

const int T = 1e5 + 10;
int v[T];
int ve[T];

int32_t main() {
    ios::sync_with_stdio(false);
    int n,q; cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i], ve[i] = v[i];

    sort(ve+1, ve+n+1);
    for(int i = 1; i <= n; i++) {
        v[i] += v[i-1];
        ve[i] += ve[i-1];
    }


    int a,b,c;
    cin >> q;
    while(q--) { 
        cin >> a >> b >> c;
        if(a == 1) cout << v[c] - v[b-1] << endl;
        else cout << ve[c] - ve[b-1] << endl;
    }

    return 0;
}

