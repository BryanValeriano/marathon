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

const int T = 3e5 + 3;
ll v[T];
ll acum[T];
ll sum;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> v[i];
    sort(v, v+n+1);

    for(int i = n-1; i >= 0; i--) acum[i] = acum[i+1] + v[i+1];

    for(int i = 0; i < n; i++) sum += acum[i]+v[i];

    cout << sum << endl;

    return 0;
}

