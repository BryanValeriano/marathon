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

const int T = 202;
int v[T];
int n,k;

vector<int> in;
vector<int> out;

ll solve(int l, int r) {
    ll sum = 0;
    in.clear();
    out.clear();

    for(int i = 0; i < n; i++) {
        if(i >= l and i <= r) in.pb(v[i]);
        else out.pb(v[i]);
    }

    int q = min((int)out.size(),k);
    sort(out.begin(), out.end(), greater<int>());
    for(int i = 0; i < q; i++) in.pb(out[i]);
    sort(in.begin(), in.end(), greater<int>());

    int ok = r-l+1;
    for(int i = 0; i < ok; i++) sum += in[i];

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;

    for(int i = 0; i < n; i++) cin >> v[i];

    ll ans = -INF;

    for(int i = 0; i < n; i++)
        for(int j = 0; i+j < n; j++) 
            ans = max(ans, solve(i,i+j));

    cout << ans << endl;

    return 0;
}

