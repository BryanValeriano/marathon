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

const int T = 1e3 + 2;
int v[T];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    int ans = 0;
    for(int i = 1; i < n-1; i++) {
        if(v[i] > v[i-1] and v[i] > v[i+1]) ans++;
        if(v[i] < v[i-1] and v[i] < v[i+1]) ans++;
    }
    cout << ans << endl;
    return 0;
}

