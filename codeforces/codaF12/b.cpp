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
const int T = 1e5+3;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    s = "#" + s;

    for(int i = 1; i < s.size(); i++) {
        v[i] += (s[i] >= 'A' and s[i] <= 'Z');
        v[i] += v[i-1];
    }

    int ans = INF;
    for(int i = 0; i < s.size(); i++)
        ans = min(ans, i+v[s.size()-1]-2*v[i]);

    cout << ans << endl;
    return 0;
}

