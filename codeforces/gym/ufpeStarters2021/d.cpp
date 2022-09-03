#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int l = 1;
    int r = n;
    int res;

    while(l <= r) {
        int mid = (l+r)>>1;
        cout << l << " " << mid << endl;
        cin >> res;
        if(res) {
            r = mid;
            if(l==r) {
                cout << "! " << r << endl;
                return 0;
            }
        }
        else l = mid+1;
    }
    return 0;
}

