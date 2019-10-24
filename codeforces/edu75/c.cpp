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
        queue<int> um;
        queue<int> dois;
        for(int i = 0; i < s.size(); i++) {
            if((s[i]-'0')&1) um.push(s[i]-'0');
            else dois.push(s[i]-'0');
        }
        while(um.size() or dois.size()) {
            if(um.size() and dois.size()) {
                int x = um.front();
                int y = dois.front();
                if(x < y) cout << x, um.pop();
                else cout << y, dois.pop();
            } else {
                if(um.size()) { cout << (um.front()); um.pop(); }
                else { cout << (dois.front()); dois.pop(); }
            }
        }
        cout << endl;
    }
    
    return 0;
}

