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
ll v[T];
int n;
int m;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> v[i], v[i] += v[i-1];
    cin >> m;
    while(m--) {
        int l,r;
        cin >> l >> r;
        cout << (v[r]-v[l-1])/10 << endl;
    }
    return 0;
}

