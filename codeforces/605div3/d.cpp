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
const int T = 2e5 + 10;

int inc[T];
int de[T];
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    v[n+1] = INF;
    v[0] = -1;
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        if(v[i] > v[i-1]) inc[i] = inc[i-1]+1;
        else inc[i] = 1;
        ans = max(ans,inc[i]);
    }

    for(int i = n; i >= 1; i--) {
        if(v[i] < v[i+1]) de[i] = de[i+1]+1;
        else de[i] = 1;
    }

    for(int i = 1; i <= n; i++)
        if(v[i-1] < v[i+1]) ans = max(ans, inc[i-1] + de[i+1]);

    cout << ans << endl;

    return 0;
}

