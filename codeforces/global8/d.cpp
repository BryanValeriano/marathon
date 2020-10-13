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
const int T = 2e5+5;
const int N = 22;
ll v[T], qtd[N];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        for(int j = 0; j < N; j++)
            if(v[i]&(1<<j)) qtd[j]++;
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++) {
        ll tmp = 0;
        for(int j = 20; j >= 0; j--)
            if(qtd[j]) qtd[j]--, tmp |= (1<<j);
        ans += tmp*tmp;
    }

    cout << ans << endl;
    return 0;
}

