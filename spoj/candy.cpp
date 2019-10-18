#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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

const int T = 1e4 + 4;
int v[T];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    while(n != -1) {
        int tot = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) cin >> v[i], tot += v[i];
        if(tot%n) { cout << -1 << endl; cin >> n; continue; }
        int z = tot/n;
        for(int i = 0; i < n; i++) ans += max(0,v[i]-z);
        cout << ans << endl;
        cin >> n;
    }
    return 0;
}

