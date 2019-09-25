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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    int h,w,a,b;
    cin >> h >> w >> a >> b;
    while(h--) {
        if(b-- > 0)cout << string(a,'0') + string(w-a,'1') << endl;
        else cout << string(a,'1') + string(w-a, '0') << endl;
    }
    return 0;
}

