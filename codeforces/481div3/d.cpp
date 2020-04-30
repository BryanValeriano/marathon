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
const int T = 1e5+3;
vector<int> v(T);
int n;

int solve(int dist, int last) {
    int ans = (last!=0);
    for(int i = 1; i < n; i++) {
        bool ok = 0;
        for(int j = -1; j <= 1; j++) {
            if((v[i-1]+last) - (v[i]+j) == dist) {
                ans += (j!=0);
                last=j;
                ok = 1;
                break;
            }
        }
        if(!ok) return INF;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> v[i];
    if(n <= 2) { cout << 0 << endl; return 0; }

    int ans = INF;

    for(int i = -1; i <= 1; i++)
        for(int j = -1; j <= 1; j++)
            ans = min(ans, solve((v[0]+i)-(v[1]+j),i));

    cout << (ans==INF?-1:ans) << endl;

    return 0;
}

