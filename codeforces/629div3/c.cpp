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

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        string s,ans1,ans2; cin >> s;
        bool z = 0;
        for(int i = 0; i < n; i++) {
            if(z) {
                ans1 += '0';
                ans2 += s[i];
            } else {
                if(s[i]=='1') {
                    ans1 += s[i];
                    ans2 += '0';
                    z = 1;
                }
                else if(s[i]=='2') {
                    ans1 += '1', ans2 += '1';
                } else ans1 += '0', ans2 += '0';
            }
        }
        cout << ans1 << endl << ans2 << endl;
    }
    return 0;
}

