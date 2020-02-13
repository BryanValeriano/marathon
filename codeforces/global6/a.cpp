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
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        string s; cin >> s;
        bool z = 0;
        int p = 0;
        int qtd = 0;

        for(int i = 0; i < s.size(); i++) {
            int x = s[i] - '0';
            qtd += x;
            qtd %= 3;
            if(!x) z = 1;
            if(!(x&1)) p++;
        }
        
        cout << (z and (p >= 2) and (!qtd)? "red" : "cyan") << endl;
    }
    return 0;
}

