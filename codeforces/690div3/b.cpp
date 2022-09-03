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
string s;
int v[4];

bool inside(int x) {
    return (x >= 0 and x < s.size());
}

bool ok(int i) {
    int j=1;
    for(j = 1; j <= i; j++) v[j-1] = j-1;
    for(; j <= 4; j++) v[j-1] = s.size()-5+j;

    //cout << i << " : ";
    //for(i = 0; i < 4; i++) cout << v[i] << " ";
    //cout << endl;

    if(v[0] > v[1] or v[1] > v[2] or v[2] > v[3]) return false;
    string x;

    if(inside(v[0])) x += s[v[0]];
    else return false;

    if(inside(v[1])) x += s[v[1]];
    else return false;

    if(inside(v[2])) x += s[v[2]];
    else return false;

    if(inside(v[3])) x += s[v[3]];
    else return false;

    //cout << x << endl;
    return (x == "2020");
}

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        cin >> s;
        bool ans = 0;
        for(int i = 0; i <= 4; i++) {
            if(ok(i)) {
                cout << "YES" << endl;
                ans = 1;
                break;
            }
        }
        if(!ans) cout << "NO" << endl;
    }
    return 0;
}

