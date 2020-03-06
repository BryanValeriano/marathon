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

const int T = 1e7+3;
const int N = 102;

vii v[T];
int ans[N];
set<ii> bag;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;

    for(int i = 1; i <= n; i++) {
        int l,r; cin >> l >> r;
        v[l].eb(r,i);
    }

    for(int i = 1; i < T; i++) {
        while(v[i].size()) {
            ii at = v[i].back();
            v[i].pop_back();
            bag.insert(at);
        }
        if(bag.size()) {
            ans[bag.begin()->se] = i;
            bag.erase(bag.begin());
        }
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

