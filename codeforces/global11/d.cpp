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
const int T = 60;
int v[T], nv[T];
int n;

void troca(int x, int y) {
    int ok = 0;
    for(int i = x; i < n; i++) nv[ok++] = v[i];
    for(int i = 0; i < x; i++) nv[ok++] = v[i];
    for(int i = 0; i < n; i++) v[i] = nv[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    vector<vector<int>> ans;

    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < n; j++)
            if(v[j] == i and j) {
                ans.eb(j,n-j);
                troca(j,n-j);
            }
    }

    cout << ans.size() << endl;

    return 0;
}

