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
const int T = 20;
int mat[T][T];

int solve(int x, int y) {
    if(x == 15 or y == 15) return 0;
    int ans = mat[x][y];
    ans += max(solve(x+1,y),solve(x+1,y+1));
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j <= i; j++) cin >> mat[i][j], cout << mat[i][j] << " ";
        cout << endl;
    cout << solve(0,0) << endl;
    return 0;
}

