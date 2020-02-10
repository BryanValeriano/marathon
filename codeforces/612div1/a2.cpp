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

const int T = 101;
int dp[T][T][T][3];
int v[T];
int n;

int solve(int at, int impar, int par, int last) {
    for(int i = 0; i < n; i++) {

        if(!v[i]) {
            if(impar) dp[i+1][impar-1][par][1] = min(dp[i+1][impar-1][par][1], dp[i

        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp, INF, sizeof dp);

    cin >> n;
    int par = n/2;
    int impar = n-par;

    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i]) {
            par -= ((v[i]&1) == 0);
            impar -= ((v[i]&1) == 1);
        }
    }

    cout << solve(0,impar,par,2)-1 << endl;
    return 0;
}

