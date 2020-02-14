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
typedef pair<char,int> si;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<int> ans;
vector<si> s;

bool isBothBad(int x) {
    return (s[x].fi == 'o' and s[x-1].fi == 'w' and s[x-2].fi == 't'
            and s[x+1].fi == 'n' and s[x+2].fi == 'e');
}

bool isOne(int x) {
    return (s[x].fi == 'n' and s[x-1].fi == 'o' and s[x+1].fi == 'e');
}

bool isTwo(int x) {
    return (s[x].fi == 'w' and s[x-1].fi == 't' and s[x+1].fi == 'o');
}

void allTwo() {
    vector<si> tmp;

    for(int i = 0; i < s.size(); i++) {
        if(i > 1 and i < s.size()-2 and isBothBad(i)) ans.pb(s[i].se);
        else tmp.pb(s[i]);
    }

    s = tmp;
}

void wOrn() {
    for(int i = 1; i < s.size()-1; i++)
        if(isOne(i) or isTwo(i)) ans.pb(s[i].se);
}


int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {

        s.clear();
        string ss; cin >> ss;
        for(int i = 0; i < ss.size(); i++) s.eb(ss[i],i+1);
        ans.clear();

        allTwo();
        wOrn();
        cout << ans.size() << endl;
        for(auto x : ans) cout << x << " ";
        cout << endl;
    }
    return 0;
}

