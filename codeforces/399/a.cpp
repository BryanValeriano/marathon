#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int I1e9+100;
const double PI = acos(-1.0);
const int T = 1e5+4;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int maxi = -INF;
    int mini = INF;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        mini = min(mini,v[i]);
        maxi = max(maxi,v[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans += (v[i] != mini && v[i] != maxi);
    cout << ans << endl;
    return 0;
}

