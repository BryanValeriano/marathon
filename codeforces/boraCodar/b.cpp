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

bool isB(string s) {
    int um = 0;
    int x = 0;
    for(int i = 0; i < s.size(); i++) {
        um += s[i] == '1';
        x += (s[i] != '0' && s[i] != '1');
    }
    return (um <= 1 && x == 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    string s;
    string ans;
    ans = "1";
    int zero = 0;

    while(n--) {
        cin >> s;
        if(s == "0") { cout << '0' << endl; return 0; }
        if(isB(s)) zero += s.size()-1;
        else ans = s;
    }
    cout << ans;
    while(zero--) cout << '0';
    cout << endl;
    return 0;
}

