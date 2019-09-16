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

const int T = 505;
char mat[T][T];
int n;

int mov[4][2] = { {1,1}, {-1,-1}, {1,-1}, {-1,1} };

bool isIn(int x, int y) {
    return (x >= 0 and y >= 0 and x < n and y < n);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> mat[i][j];

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            bool ok = 1;
            if(mat[i][j] == '.') continue;
            for(int k = 0; k < 4; k++)  {
                int ii = i + mov[k][0];
                int jj = j + mov[k][1];
                if(isIn(ii,jj)) ok &= mat[ii][jj] == 'X';
                else ok = 0;
            }
            ans += ok;
        }
    }

    cout << ans << endl;

    return 0;
}

