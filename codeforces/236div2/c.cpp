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
        int n, p; cin >> n >> p;
        int k = 0;

        for(int i = 1; i <= n and k < 2*n+p; i++)
            for(int j = i+1; j <= n and k < 2*n+p; j++)
                cout << i << " " << j << endl, k++;
    }
    return 0;
}

