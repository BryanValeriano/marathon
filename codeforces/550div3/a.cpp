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

bool noDup(string s) {
    int v[30];
    for(int i = 0; i < 30; i++) v[i] = 0;
    for(int i = 0; i < s.size(); i++) {
        v[s[i]-'a']++;
        if(v[s[i]-'a'] == 2) return false;
    }
    sort(s.begin(), s.end());
    for(int i = 1; i < s.size(); i++)
        if(s[i] - s[i-1] != 1) return false;
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    string s;
    while(tc--) {
        cin >> s;
        if(s.size() == 1 or noDup(s)) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
    return 0;
}

