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
const int T = 102;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n, ans = 0; cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v, v+n);
    for(int i = 1; i < n; i+= 2) ans += v[i] - v[i-1]; 
    cout << ans << endl;
    return 0;
}

