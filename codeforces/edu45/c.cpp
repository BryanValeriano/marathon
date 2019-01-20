#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        int cont = 0;
        bool flag = false;
        bool flag2 = false;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == '(') cont++;
            else cont--;
            if(cont < 0) flag = true;
        }
        int cont2 = 0;
        for(int j = s.size()-1; j >= 0; j--) {
            if(s[j] == '(') cont2++;
            else cont2--;
            if(cont2 > 0) flag2 = true;
        }

        if((flag and cont >= 0) or (flag2 and cont2 <= 0)) continue;
        v.pb(cont);
    }
    sort(v.begin(), v.end());

    ll ans = 0;

    for(int i = 0; i < v.size() and v[i] <= 0; i++) {
        int low = lower_bound(v.begin(), v.end(), -v[i]) - v.begin();
        int up = upper_bound(v.begin(), v.end(), -v[i]) - v.begin();
        if(low < v.size() and v[low] == -v[i]) ans += (up - low);
    }
    cout << ans << endl;
    return 0;
}

