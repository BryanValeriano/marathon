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

const int T = 11;
const int N = 8;
int dp[T][N];


int main() {
    ios_base::sync_with_stdio(false);
    dp[1][1] = 1;
    int a,b; cin >> a >> b;

    for(int i = 1; i < T; i++) {
        for(int j = 1; j < N; j++) {
            if(10-i < a and j <= b) continue;
            dp[i][j] += dp[i-1][j] + dp[i][j-1];
        }
    }

    for(int i = 1; i < T; i++) {
        for(int j = 1; j < N; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

