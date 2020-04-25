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
const int T = 110;
int n;
string s;

bool isIn(int i) {
    return (i >= 0 and i < n);
}

bool doLado(int i) {
    if(isIn(i-1) and s[i-1] == '*') return true;
    if(isIn(i+1) and s[i+1] == '*') return true;
    return false;
}

bool notSafe(int i) {
    if(s[i] == '*' or s[i] == 'x')
        return false;
    if(isIn(i - 1) and s[i-1] == '*')
        return false;
    if(isIn(i + 1) and s[i+1] == '*')
        return false;
    return true;
}

void coloca(int i) {
    s[i] = '*';
    if(isIn(i-1)) s[i-1] = 'x';
    if(isIn(i+1)) s[i+1] = 'x';
    return;
}


int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        cin >> s;
        int ans = 0;
        for(int i = 0; i < n; i++)
            if(doLado(i)) s[i] = 'x';
        for(int i = 0; i < n; i++) 
            if(isIn(i) and notSafe(i)) {
               if(isIn(i+1) and notSafe(i+1)) { coloca(i+1); ans++; }
               else { coloca(i); ans++; }
            }
        cout << ans << endl;
    }
    return 0;
}

