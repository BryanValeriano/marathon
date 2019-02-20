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
const int T = 2e5 + 10;
int v[T];
ll odd[T];
ll even[T];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        if(i&1) odd[i] = v[i];
        else even[i] = v[i];
    }
    for(int i = 0; i <= n; i++) {
        odd[i] += odd[i-1];
        even[i] += even[i-1];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ll par = even[i-1] + (odd[n] - odd[i]);
        ll impar = odd[i-1] + (even[n] - even[i]);
        ans += (par == impar);
    }
    cout << ans << endl;
    return 0;
}

