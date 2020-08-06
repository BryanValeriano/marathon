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
    int tc; cin >> tc;
    while(tc--) {
        ll n,k; cin >> n >> k;
        k--;
        ll first = 0;
        ll shift1 = 1;
        ll shift2 = 0;
        while(first+shift1 <= k) first += shift1, shift1++;
        shift2 = k-first;
        int pos1 = n-shift1-1, pos2 = n-shift2-1;
        for(int i = 0; i < n; i++) cout << (i==pos1 or i==pos2?'b':'a');
        cout << endl;
    }
    return 0;
}

