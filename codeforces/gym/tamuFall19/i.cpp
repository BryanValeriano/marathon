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
int p[T];
int s[T];

string solve(int a, int b) {
    int pp = p[b] - p[a-1];
    int ss = s[b] - s[a-1];
    if(ss > pp) return "INCREASE";
    if(ss < 0 and abs(ss) > pp) return "DECREASE";
    return "STABLE";
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,q;cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> p[i], p[i] += p[i-1];
    for(int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i-1];
    while(q--) {
        int a,b; cin >> a >> b;
        cout << solve(a,b) << endl;
    }
    return 0;
}

