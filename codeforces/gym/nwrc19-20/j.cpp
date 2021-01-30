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
const int T = 505;
string g[T];
int n;

string solve(int pos) {
    for(int i = pos+1; i < n; i++) {
        if(g[pos][i] == '1') {
            for(int j = i+1; j < n; j++) {
                g[pos][j] = ((g[pos][j] - g[i][j] + 10)%10)+'0';
            }
        }
    }
    return g[pos];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> g[i];
    for(int i = 0; i < n; i++)
        cout << solve(i) << endl;
    return 0;
}
