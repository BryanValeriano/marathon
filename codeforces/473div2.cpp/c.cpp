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
    int n; cin >> n;
    if(n <= 5) cout << -1 << endl;
    else {
        for(int i = 2; i <= n-2; i++)
            cout << 1 << " " << i << endl;
        cout << 2 << " " << n-1 << endl;
        cout << 2 << " " << n << endl;
    }
    for(int i = 2; i <= n; i++)
        cout << 1 << " " << i << endl;

    return 0;
}

