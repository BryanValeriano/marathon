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
    int n; cin >> n;
    string s; cin >> s;
    int u = 0;
    int z = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') u++;
        else z++;
    }
    if(u != z) cout << 1 << endl << s << endl;
    else {
        cout << 2 << endl;
        char ok = s.back();
        s.pop_back();
        cout << s << " " << ok << endl;
    }

    return 0;
}

