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

void fu() {
    cout << "No solution" << endl;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    vector<string> ans;
    string x;
    int op = 0;

    for(int i = 0; i < s.size(); i++) {
        x += s[i];

        if(s[i] == '@') {
            if(op != 1) fu();
            op = 2;
        }

        else if(s[i] != '@') {
            if(op == 2) op = 0, ans.pb(x), x = "";
            else op = 1;
        }
    }

    if(op == 1) {
        if(ans.size()) ans.back() += x;
        else fu();
    }
    else if(op == 2) fu();

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i + 1 < ans.size()? "," : "\n");
    }

    return 0;
}

