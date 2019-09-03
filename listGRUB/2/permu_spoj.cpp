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

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        if(n&1) { cout << -1 << endl; continue; }
        for(int i = 1; i <= n; i++) 
            cout << (i & 1? i + 1 : i - 1) << " ";
        cout << endl;
    }
    return 0;
}

