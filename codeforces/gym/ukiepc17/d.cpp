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
    string s; cin >> s;
    vector<ii> ans;
    int ini = 0;

    for(char i = 'a'; i <= 'z'; i++) {
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == i) {
                if(ini != j) {
                    ans.eb(j+1,ini+1);
                    swap(s[j],s[ini]);
                }
                ini++;
            }
        }
    }

    reverse(ans.begin(),ans.end());
    for(auto ok : ans) cout << ok.fi << " " << ok.se << endl;

    return 0;
}

