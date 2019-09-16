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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

string s;
const int T = 2e5 + 2;
ll po[30];
ll zeros[T + 3];
ll at;
ll casa;


int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;

    po[0] = 1;
    for(int i = 1; i < 20; i++) po[i] = po[i-1]*2;

    while(tc--) {
        cin >> s;
        ll ans = 0;
        reverse(s.begin(), s.end());

        for(int i = 0; i < s.size()+2; i++) zeros[i] = 0;

        for(int i = s.size()-1; i >= 0 ; i--) {
            zeros[i] += zeros[i+1];
            if(s[i] == '0') zeros[i]++;
            else zeros[i] = 0;
        }

        for(int i = 0; i < s.size(); i++) {
            int j = i;
            at = casa = 0;
            while(j < s.size() and casa < 19) {
                if(s[j] == '1') at += po[casa];

                if(j-i+1 == at) ans++;
                else if(casa == 18 and at > casa) {
                    ll dist = at - casa;
                    if( (s[j] != '1' and zeros[j] >= dist) or
                        (s[j] == '1' and zeros[j+1] >= dist) ){
                        ans++;
                    }
                }
                casa++;
                j++;
            }
        }

        cout << ans << endl;
    }
    return 0;
}

