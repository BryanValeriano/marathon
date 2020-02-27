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
const double PI = acos(-1.0);

const int T = 1e5 + 5;
ll v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        ll a,b,p; cin >> a >> b >> p;
        string s; cin >> s;
        s = '#' + s;

        for(int i = 0; i < s.size(); i++) v[i] = 0;

        v[1] = (s[1] == 'A'? a : b);

        for(int i = 2; i < s.size(); i++) {
            v[i] += v[i-1];
            if(s[i] != s[i-1]) v[i] += (s[i] == 'A'? a : b);
        }

        ll cf = v[s.size()-2];
        int ok = s.size()-1;

        for(int i = 1; i < s.size(); i++) {
            if(s[i] != s[i-1] and cf - v[i-1] <= p) { ok = i; break; }
        }

        cout << ok << endl;
    }



    return 0;
}

