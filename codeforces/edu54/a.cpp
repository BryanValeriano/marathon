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
    int n; cin >> n;
    string s; cin >> s;
    int eq = 0;
    int pos = -1;
    for(int i = 0; i < s.size() - 1; i++) {
        if(s[i+1] == s[i]) eq++;
        if(s[i+1] < s[i]) { pos = i; break; }
    }
    if(pos == -1 && eq != s.size()-1)
        pos = s.size() - 1;
    else if(pos == -1) pos = 1; 

    for(int i = 0; i < s.size(); i++)
        if(i != pos) cout << s[i];
    cout << endl;

    return 0;
}

