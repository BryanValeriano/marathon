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
const int T = 17;
const int MOD = 1e9+7;

ll probs[T][T][T][T];
ll qtd[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    ll ans = 1;
    for(int i = 1; i <= n; i++) ans = (ans*i)%MOD;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                for(int p = 1; p <= n; p++)
                    if(i+j%n+1 == k+p%n+1) probs[i][j][k][p] = 1;



    return 0;
}

