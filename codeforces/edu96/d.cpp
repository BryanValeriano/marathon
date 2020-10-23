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
string s;
vector<int> v;

vector<int> cond() {
    int at = 1;
    vector<int> v;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] != s[i-1]) {
            v.pb(at);
            at = 1;
        } else at++;
    }
    v.pb(at);
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        cin >> s;
        v = cond();
        int ans = 0, l = 0, r = 0;
        bool corn = 0;
        n = v.size();

        while(l < n) {
            r = max(r,l);
            if(!corn) {
                while(r < n and v[r] == 1) r++;
                if(r == n) corn = 1;
                else v[r]--;
            }
            if(corn) v[l]--;;
            while(l < n and !v[l]) l++;
            ans++;
            l++;
        }
        cout << ans << endl;
    }
    return 0;
}

