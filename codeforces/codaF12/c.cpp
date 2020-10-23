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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 5e3+4;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v[x]++;
    }

    for(int i = 1; i < T; i++) v[i] += v[i-1];

    int ans = INF;
    int l = 1;
    int r = 1;

    while(l < T) {
        while(r < T and l*2 > r) r++;
        ans = min(ans, n-(v[r]-v[l-1]));
        l++;
    }

    cout << ans << endl;
    return 0;
}

