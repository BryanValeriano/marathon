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
const int T =55;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }

        if(sum == 0) {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";

        if(sum < 0) sort(v,v+n);
        else sort(v,v+n,greater<int>());
        for(int i = 0; i < n; i++) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}

