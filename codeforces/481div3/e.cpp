#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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

int main() {
    ios_base::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    int maxi = 0, mini = 0;
    int at = 0;

    while(n--) {
        int x; cin >> x;
        at += x;
        maxi = max(maxi,at);
        mini = min(mini,at);
    }

    int high = k-maxi, low = abs(mini);
    cout << max(high-low+1,0) << endl;

    return 0;
}

