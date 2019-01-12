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
    int tc; cin >> tc;
    string s;
    getline(cin,s);
    while(tc--) {
        string s1,s2;
        getline(cin,s);
        if(s.size() >= 4) {
            s1 += s[0]; s1 += s[1]; s1 += s[2]; s1 += s[3];
            s2 += s[s.size()-4]; s2 += s[s.size()-3]; s2 += s[s.size()-2]; s2 += s[s.size() - 1];
        }
        size_t find = s.find(" not ");
        if(find != string::npos or s == "not" or s1 == "not " or s2 == " not" ) cout << "Real Fancy" << endl;
        else cout << "regularly fancy" << endl;
        //cout << s1 << " " << s2 << endl;
    }
    return 0;
}

