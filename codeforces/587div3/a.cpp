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
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    int a = 0, b = 0;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'a') a++;
        else b++;
        if(i&1) {
            if(a > b) ans++, b++, a--, s[i] = 'b';
            else if(b > a) ans++, a++, b--, s[i] = 'a';
        }
    }

    cout << ans << endl;
    cout << s << endl;

    
    
    return 0;
}

