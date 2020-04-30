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
    int n; string s;
    cin >> n >> s;
    int ans = 0;
    int row = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'x') row++;
        else row = 0;
        ans += (row > 2);
    }
    cout << ans << endl;

    return 0;
}

