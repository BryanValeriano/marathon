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

const int C = 31;
const int T = 1e5 + 2;
int v[C][T];
int ok[T];
int n,c;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> c;

    for(int i = 0; i < n; i++) {
        int s,t,ci;
        cin >> s >> t >> ci;
        v[ci][s]++;
        v[ci][t+1]--;
    }

    int ans = 0;

    for(int i = 1; i < C; i++) {
        for(int j = 1; j < T; j++) v[i][j] += v[i][j-1];
        for(int j = 0; j < T; j++) {
            v[i][j] = min(v[i][j],1);
            ok[j] += v[i][j];
            ans = max(ans,ok[j]);
        }
    }

    cout << ans << endl;
    return 0;
}

