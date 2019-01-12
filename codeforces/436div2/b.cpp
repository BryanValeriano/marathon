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
int n;
string s;

int pretty(int x, int y) {
    set<char> lower;
    for(int i = x; i <= y; i++) {
        if(s[i] >= 'a' and s[i] <= 'z') {
            if(lower.count(s[i])) continue;
            lower.insert(s[i]);
        } else return lower.size();
    }
    return lower.size();
}
            


int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;
    int ans = 0;
    if(n == 1) {
        cout << (s[0] >= 'a' and s[0] <= 'z'? 1 : 0) << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            int tmp = pretty(i,j);
            ans = max(ans, tmp);
        }
    cout << ans << endl;
    return 0;
}

