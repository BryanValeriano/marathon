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

const int T = 2000;

int main() {
    ios::sync_with_stdio(false);
    int ans = 0;

    for(int x = 1; x <= T; x++) {
        ans = 0;
        for(int y = x; y <= T; y++) {
            if((y%x) == (y^x)) ans++; 
        }
        cout << x << " " << ans << " " << __builtin_popcount(x) << endl;
    }

    return 0;
}

