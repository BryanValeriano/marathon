#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        int n; cin >> n;
        string s; cin >> s;
        cout << "Case #" << ++cont << ": ";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'S') cout << 'E';
            else cout << 'S';
        }
        cout << endl;
    }
    return 0;
}

