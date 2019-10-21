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
const ll MOD = 1e6;

const int T = 205;

ll choose[T][T];

void solve() {
    for(int i = 0; i < T; i++) choose[i][0] = 1;
    for(int j = 0; j < T; j++) choose[j][j] = 1;

    for(int i = 1; i < T; i++)
        for(int j = 1; j < T; j++)
            choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) % MOD;
}


int main() {
    ios_base::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;
    solve();
    while(a or b) {
        cout << choose[a+b-1][b-1] << endl;
        cin >> a >> b;
    }
    return 0;
}

