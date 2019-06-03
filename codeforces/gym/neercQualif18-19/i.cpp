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
    int maxi = 0;
    int mini = INF;
    int n, x; cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> x;
        maxi = max(maxi, x);
        mini = min(mini, x);
    }

    cout << ((maxi-mini+1) - n) << endl;

    return 0;
}

