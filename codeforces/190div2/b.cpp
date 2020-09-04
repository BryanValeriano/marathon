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
const int T = 4;
int dp[T][T][T];
int a[T];

int solve(int v[T]) {
    int &r = dp[v[0]][v[1]][v[2]];
    if(r!=-1) return r;
    r = 0;

    for(int i = 0; i < 3; i++) {
        if(v[i]==3) {
            v[i] -= 3;
            r = max(r,solve(v)+1);
            v[i] += 3;
        }
    }

    for(int i = 1; i <= 3; i++) {
        bool ok = 1;
        for(int j = 0; j < 3; j++) ok &= (i<=v[j]), v[j] -= i;
        if(ok) r = max(r,solve(v)+1);
        for(int j = 0; j < 3; j++) v[j] += i;
    }

    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    memset(dp,-1,sizeof dp);
    for(int i = 0; i < 3; i++) cin >> a[i];
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        if(a[i]%3) ans += a[i]/3, a[i] = a[i]%3;
        else ans += max(0,a[i]/3-1), a[i] = min(a[i],3);
    }
    cout << (ans+solve(a)) << endl;
    return 0;
}

