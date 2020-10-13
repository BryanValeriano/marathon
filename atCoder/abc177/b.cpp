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
    string s, t;
    cin >> s >> t;

    int ans = INF;
    int n = t.size();

    for(int i = 0; i+n-1 < s.size(); i++) {
        int tmp = 0;
        for(int j = 0; j < n; j++) tmp += s[i+j] != t[j];
        ans = min(ans,tmp);
    }

    cout << ans << endl;
    return 0;
}

