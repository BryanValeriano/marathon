#include <bits/stdc++.h>
using namespace std;

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
    int n; cin >> n;
    int ans = 0;
    while(n--) {
        int x,y;
        cin >> x >> y;
        if(x==y) ans++;
        else ans = 0;
        if(ans==3) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}

