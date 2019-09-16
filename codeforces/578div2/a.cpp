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

string ans = "0000000000";
int n;

void pega(int ini, int pas) {
    for(int i = ini; i < 10 and i >= 0; i += pas)
        if(ans[i] == '0') { ans[i] = '1'; return; }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    string s; cin >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L') pega(0,1);
        else if(s[i] == 'R') pega(9,-1);
        else ans[s[i]-'0'] = '0';
    }
    cout << ans << endl;
    return 0;
}

