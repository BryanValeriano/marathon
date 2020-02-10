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
    int n;
    cin >> n;
    while(n--) {
        string s; cin >> s;
        if(s.back() == 'a') s += "s";
        else if(s.back() == 'i') s +=  "os";
        else if(s.back() == 'y') {
            s.pop_back();
            s += "ios";
        }
        else if(s.back() == 'l') s += "es";
        else if(s.back() == 'n') {
            s.pop_back();
            s += "anes";
        }
        else if(s.size() >= 2 and s.back() == 'e' and s[s.size()-2] == 'n') {
            s.pop_back(); s.pop_back();
            s += "anes";
        }
        else if(s.back() == 'o') s += "s";
        else if(s.back() == 'r') s += "es";
        else if(s.back() == 't') s += "as";
        else if(s.back() == 'u') s += "s";
        else if(s.back() == 'v') s += "es";
        else if(s.back() == 'w') s += "as";
        else s += "us";
        cout << s << endl;
    }
    return 0;
}

