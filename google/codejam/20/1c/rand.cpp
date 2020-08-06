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
typedef pair<int,char> ic;
typedef vector<ic> vic;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 30;

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        string u; cin >> u;
        int freq[T];
        int aper[T];
        memset(freq,0,sizeof freq);
        memset(aper,0,sizeof aper);
        for(int i = 0; i < 1e4; i++) {
            string x; cin >> x;
            string s; cin >> s;
            freq[s[0]-'A']++;
            for(int j = 0; j < s.size(); j++) aper[s[j]-'A']++;
        }

        vic v;
        for(int i = 0; i < T; i++) {
            if(aper[i]) {
                v.eb(freq[i],((char)(i+'A')));
            }
        }
        sort(v.begin(),v.end(),greater<ic>());
        string ans;
        ans += v.back().se;
        for(int i = 0; i < v.size()-1; i++) ans += v[i].se;
        cout << "Case #" << ++cont << ": " << ans << endl;
    }

    return 0;
}

