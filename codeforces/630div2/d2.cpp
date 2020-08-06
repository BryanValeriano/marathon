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
const int Z = (1<<18)-1;
int ans[3][3];

int main() {
    ios_base::sync_with_stdio(false);
    int K; cin >> K;
    cout << 3 << " " << 3 << endl;
    int Y = K^Z;
    ans[0][0] = ans[0][1] = ans[1][2] = Z;
    ans[1][0] = ans[2][0] = ans[0][2] = Y;
    ans[1][1] = ans[2][2] = K;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}

