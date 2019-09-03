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


string solve(string s) {
    string t;
    bool flag = false;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '4') flag = true, t += '1';
        else if(flag) t += '0';
    }
    return t;
}
        
string tira(string s) {
    for(int i = 0; i < s.size(); i++) 
        if(s[i] == '4') s[i]--;
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int cont = 0;
    while(tc--) {
        string s; cin >> s;
        string t = solve(s);
        s = tira(s);
        cout << "Case #" << ++cont << ": "<< s << " " << t << endl;
    }
    return 0;
}

