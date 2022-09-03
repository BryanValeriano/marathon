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

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        string s,t; cin >> s >> t;
        string tmp = t;

        vector<int> v;

        for(int i = 0; i < n; i++)
            if(s[i] != t[i]) v.pb(i);


        for(int i = 1; i < v.size(); i++) {
            t[v[i]] = tmp[v[i-1]];
        }

        if(v.size()) t[v[0]] = tmp[v.back()];
        cout << (s==t? "YES" : "NO") << endl;
    }
    return 0;
}

