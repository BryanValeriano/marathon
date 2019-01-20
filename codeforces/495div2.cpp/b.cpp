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

int main() {
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    int aux1, aux2;
    for(int i = 0; i < m; i++) cin >> aux1 >> aux2;
    for(int i = 1; i <= n; i++) cout << (i & 1? 0 : 1);
    cout << endl;
    return 0;
}

