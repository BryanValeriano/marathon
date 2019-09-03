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
const int T = 1e3 + 100;
int c[T];

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        if(n == 1) { cout << 1 << endl; return 0; }
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++) 
            cin >> c[i];
        for(int i = 0; i < n-1; i++) {
            if(sum + c[i] < c[i+1]) {
                sum += c[i];
                ans++;
            }
        }
        cout << ans+1 << endl;
    }
    return 0;
}

