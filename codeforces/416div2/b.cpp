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

const int T = 1e4 + 5;
int v[T];
int mini[T];
int maxi[T];
int pos[T];

int main() {
    ios::sync_with_stdio(false);
    int n, m, x, l, r;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> pos[i];
        v[pos[i]] = i;
    }

    mini[1] = v[1];
    maxi[1] = v[1];

    for(int i = 2; i <= n; i++) {
        mini[i] = maxi[i] = v[i];
        mini[i] = min(mini[i], mini[i-1]);
        maxi[i] = max(maxi[i], maxi[i-1]);
    }

    while(m--) {
        cin >> l >> r >> x;
        cout << pos[x] << " " << mini[pos[x]] << " " << maxi[pos[x]] << endl;
        if(mini[pos[x]] >= l and maxi[pos[x]] <= r) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}

