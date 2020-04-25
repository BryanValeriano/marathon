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
const int T = 32;
const int S = 101;

int ss[S];
int qq[T];
int que[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n,q,s;
    cin >> n >> q >> s;
    for(int i = 0; i < s; i++) cin >> ss[i], ss[i]--;
    for(int i = 0; i < q; i++) cin >> qq[i];
    bool ans = 1;
    while(n-- and ans) {
        int d; cin >> d;
        memset(que,0,sizeof que);
        int sum = 0;
        for(int i = 0; i < s; i++) {
            int x; cin >> x;
            sum += x;
            que[ss[i]] += x;
            ans &= (que[ss[i]] <= qq[ss[i]]);
        }
        ans &= (sum <= d);
    }

    cout << (ans? "possible" : "impossible") << endl;

    return 0;
}

