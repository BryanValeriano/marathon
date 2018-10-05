#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

bool decode(string s, int i, int flag) {
    if(i >= s.size()) return true;
    if((i == s.size() - 1) && ((s[i] == '4' && flag == 0) || s[i] == '1')) return true;
    if((s[i] == '1') && (s[i+1] == '1' || s[i+1] == '4'))
        return decode(s, i+1,0); 
    else if(s[i] == '4' && i - 1 >= 0 && i + 1 < s.size() && s[i-1] == '1' && s[i+1] == '4')
        return decode(s, i+2,1);
    else if((s[i] == '4') && (s[i+1] == '1') && (flag == 0)) 
        return decode(s, i+1,0);
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    if(s[0] == '4') cout << "NO" << endl;
    else cout << (decode(s,0,0)? "YES" : "NO") << endl;
    return 0;
}

