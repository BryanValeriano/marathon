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

int cont(string s) {
    int um = 0;
    int zero = 0;
    for(int i = 1; i < s.size(); i++)
        if(s[i] == '1' and s[i] == s[i-1]) um++;
    for(int i = 1; i < s.size(); i++)
        if(s[i] == '0' and s[i] == s[i-1]) zero++;

    return max(um,zero);
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        string s; cin >> s;
        cout << cont(s) << endl;
    }
    return 0;
}

