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
    int n,k,t;
    cin >> n >> k >> t;
    if(t < k) {
        cout << t << endl;
    } else if(t > n) {
        cout << k - (t-n) << endl;
    } else cout << k << endl;
    return 0;
}

