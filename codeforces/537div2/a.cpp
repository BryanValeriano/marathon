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

bool isV(char x) {
    if(x == 'a' or x == 'e' or x == 'o' or x == 'u' or x == 'i') 
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    
    if(s.size() != t.size()) { cout << "No" << endl; return 0; }
    for(int i = 0; i < s.size(); i++) 
        if(isV(s[i]) != isV(t[i])) { cout << "No" << endl; return 0; }
    
    cout << "Yes" << endl;
    return 0;
}

