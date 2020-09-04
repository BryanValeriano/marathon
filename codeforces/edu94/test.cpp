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
const int T = 3e5+5;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++)
            for(int k = j+1; k < n; k++) {
                if(v[i] != v[k]) continue;
                for(int l = k+1; l < n; l++) {
                    if(v[j] != v[l]) continue;
                    //if(v[i] != v[j]) ans++;
                    ans++;
                    if(v[i] != v[j])
                        cout << i << " " << j << " " << k << " " << l << endl;
                }
            }
    cout << ans << endl;
    return 0;
}

