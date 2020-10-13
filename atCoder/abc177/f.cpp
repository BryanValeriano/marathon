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
set<int> bag;

int check(int at, int ans) {
    if(bag.empty()) return ans;
    auto golpe = bag.upper_bound(at);
    if(golpe == bag.begin()) return ans;
    golpe--;
    if(golpe == bag.begin()) return ans;
    return ans - ((*golpe)-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    int h,w; cin >> h >> w;
    for(int i = 1; i <= w; i++) bag.insert(i);

    int ans = 0;
    int at = 1;

    for(int i = 0; i < h; i++) {
        int l,r; cin >> l >> r;
        ans++;
        vector<int> del;
        while(at >= l and at <= r) at++, ans++;
        cout << (at > w? -1 : check(at,ans)) << endl;
        for(auto j = bag.lower_bound(l); j != bag.end() and *j <= r; j++) del.pb(*j);
        for(int j : del) bag.erase(j);
    }
    return 0;
}

