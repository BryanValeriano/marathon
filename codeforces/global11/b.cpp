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
const int T = 2e5+5;
int gaps[T];
vii cords[T];
string s;

void doIt(ii tmp) {
    for(int i = tmp.fi; i <= tmp.se; i++) s[i] = 'W';
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n,k; cin >> n >> k;
        cin >> s;
        bool ok = 0;
        int at = 0;
        int last = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'L' and ok) at++;
            if(s[i] == 'W') {
                if(!ok) ok = 1;
                else if(at) {
                    cords[at].eb(last+1,i-1);
                    gaps[at]++, at = 0;
                }
                last = i;
            }
        }

        for(int i = 1; i < n; i++) {
            if(k) {
                at = min(k/i,gaps[i]);
                if(at) {
                    k -= at*i;
                    for(int j = 0; j < at; j++)
                        doIt(cords[i][j]);
                }
            }
            gaps[i] = 0;
            cords[i].clear();
        }

        for(int i = 1; i < n and k; i++)
            if(s[i] == 'L' and s[i-1] == 'W')
                s[i] = 'W', k--;

        for(int i = n-2; i >= 0 and k; i--)
            if(s[i] == 'L' and s[i+1] == 'W')
                s[i] = 'W', k--;

        for(int i = 0; i < n; i++) {
            if(s[i] == 'L' and k) s[i] = 'W', k--;
            if(s[i] == 'W') {
                ans++;
                if(i and s[i-1] == 'W') ans++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}

