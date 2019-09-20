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

const int T = 1e3 + 3;
ll v[T];
ll g[T][T];
int n;


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    ll x;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];

    v[0] = (g[0][2]*g[0][1]) / g[1][2];
    v[0] = sqrt(v[0]);

    cout << v[0] << " ";
    for(int i = 1; i < n; i++) cout << g[0][i]/v[0] << " ";
    cout << endl;

    return 0;
}

