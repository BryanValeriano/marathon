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

bool notN(string s) {
    for(int i = 1; i < s.size(); i++)
        if(s[i] == '1' and (s[i] == s[i-1])) return false;
    return true;
}

bool notP(int pos, string s) {
    if(s[pos] == '1') return true;
    s[pos] = '1';
    return !notN(s);
}

int main() {
    ios::sync_with_stdio(false);
    int n; string s;
    cin >> n >> s;

    bool ans = true;
    if(notN(s)) 
        for(int i = 0; i < n; i++) ans &= notP(i,s);
    else ans = false;

    cout << (ans? "YES" : "NO") << endl;

    return 0;
}

