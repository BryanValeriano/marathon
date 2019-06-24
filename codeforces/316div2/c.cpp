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
    int n, q;
    string s;
    cin >> n >> q >> s;
    int ans = 0;

    for(int i = 1; i < n; i++) 
        if(s[i] == '.' and s[i-1] == '.') ans++;

    while(q--) {
        int x;
        char y;
        cin >> x >> y;
        x--;

        if(x-1 >= 0 and s[x] == '.' and s[x-1] == '.' and y != '.') ans--;
        if(x+1 < n and s[x] == '.' and s[x+1] == '.' and y != '.') ans--;
        if(x-1 >= 0 and s[x] != '.' and s[x-1] == '.' and y == '.') ans++;
        if(x+1 < n and s[x] != '.' and s[x+1] == '.' and y == '.') ans++;

        s[x] = y;
        cout << ans << endl;
    }

    return 0;
}

