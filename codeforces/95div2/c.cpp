#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 33;

ll v[T][T];

ll escolhe() {
    for(int i = 0; i < T; i++) v[i][0] = 1;
    for(int j = 0; j < T; j++) v[j][j] = 1;

    for(int i = 1; i < T; i++)
        for(int j = 1; j < T; j++)
            v[i][j] = v[i-1][j-1] + v[i-1][j];
}

int main() {
    ios::sync_with_stdio(false);
    escolhe();
    ll a,b,c;
    cin >> a >> b >> c;

    ll ans = 0;

    for(int i = 4; i <= min(a,c-1); i++)
        if(c-i <= b) ans += v[a][i] * v[b][c-i];

    cout << ans << endl;

    return 0;
}

