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

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    string ans;
    string um;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '1') um += s[i];
        else ans += s[i];
    }
    bool flag = true;
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] == '2' and flag) {
            cout << um;
            flag = false;
        }
        cout << ans[i];
    }
    if(flag) cout << um;
    cout << endl;
    return 0;
}

