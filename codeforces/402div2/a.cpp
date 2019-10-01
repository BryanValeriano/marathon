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

int a[6];
int b[6];
int n;
 
int main() {
    ios_base::sync_with_stdio(false);
    int x;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> x, a[x]++;
    for(int i = 0; i < n; i++) cin >> x, b[x]++;

    int ans = 0;
    for(int i = 1; i <= 5; i++) {
        if((a[i]+b[i])&1) { cout << -1 << endl; return 0; }
        ans += abs(a[i]-b[i]);
    }
    cout << ans/4 << endl;
    return 0;
}

