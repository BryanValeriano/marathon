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
const int T = 1030;
int v[T];
int freq1[T], freq2[T];
int n;

bool ok(int x) {
    bool ans = true;
    for(int i = 0; i < n; i++) freq2[v[i]^x]++;
    for(int i = 0; i < n; i++) ans &= (freq2[v[i]] == freq1[v[i]]);
    for(int i = 0; i < n; i++) freq2[v[i]^x]--;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            freq1[v[i]]++;
        }
        sort(v,v+n);
        int ans = -1;
        for(int i = 1; i < T; i++) {
            if(ok(i)) {
                ans = i;
                break;
            }
        }
        cout << ans << endl;
        for(int i = 0; i < n; i++) freq1[v[i]]--;
    }
    return 0;
}

