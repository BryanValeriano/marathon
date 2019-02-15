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
    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        string s; cin >> s;
        if(n == 2 and s[0] >= s[1]) 
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            cout << 2 << endl;
            cout << s[0] << " ";
            for(int i = 1; i < n; i++) cout << s[i];
            cout << endl;
        }
    }
    return 0;
}

