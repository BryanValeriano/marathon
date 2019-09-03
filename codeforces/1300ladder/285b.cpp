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
const int T = 1e5 + 3;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n, ini, fim; cin >> n >> ini >> fim;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    int t = 0;
    while(ini != fim and t < n+2) {
        t++;
        ini = v[ini];
    }
    cout << (t == n+2? -1 : t) << endl;
    return 0;
}

