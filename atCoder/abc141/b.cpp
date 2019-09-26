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

void partiu() {
    cout << "No" << endl;
    exit(0);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s;
    s = "1" + s;
    for(int i = 1; i < s.size(); i++) {
        if(i&1) { if(s[i] != 'R' and s[i] != 'U' and s[i] != 'D') partiu(); }
        else if(s[i] != 'L' and s[i] != 'U' and s[i] != 'D') partiu();
    }
    cout << "Yes" << endl;
    return 0;
}

