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
const int T = 1e5+5;
int v[T], rest[T];
int n;

bool check(int k) {
    k++;
    set<int> bag;
    for(int i = 0; i < n; i++) bag.insert(i), rest[i] = v[i];

    for(int i = 0; i < n; i++) {
        int last = -k;
        while(rest[i]) {
            auto pos = bag.lower_bound(last+k);
            if(pos == bag.end()) {
                cout << i << " " <<rest[i] << endl;
                return false;
            }
            last = *pos;
            bag.erase(pos);
            rest[i]--;
            cout << last << endl;
            if(!rest[i]) cout << "---\n";
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;

    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++) v[i] = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            x--;
            v[x]++;
        }

        sort(v,v+n, greater<int>());
        int l = 0;
        int r = n;
        int ans = 0;

        check(2);
        return 0;

        while(l <= r) {
            int mid = (l+r) >> 1;
            if(check(mid)) l = mid+1, ans = mid;
            else r = mid-1;
        }

        cout << (ans) << endl;
    }

    return 0;
}

