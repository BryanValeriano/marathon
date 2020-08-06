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
const int T = 1010;
int dv[11] = {2,3,5,7,11,13,17,19,23,29,31};
int volta[11];
int ans[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        set<int> bag;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            for(int j = 0; j < 11; j++) {
                if(x%dv[j]==0) {
                    ans[i] = j+1;
                    bag.insert(j+1);
                    break;
                }
            }
        }
        int i = 0;
        for(auto x : bag) volta[x] = ++i;
        cout << bag.size() << endl;
        for(int i = 0; i < n; i++) cout << volta[ans[i]] << " ";
        cout << endl;
    }
    return 0;
}

