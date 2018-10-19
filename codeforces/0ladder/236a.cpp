#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    set<char>ind;
    string s; cin >> s;
    for(int i = 0; i < s.size(); i++) 
        ind.insert(s[i]);
    cout << (ind.size()&1? "IGNORE HIM!" : "CHAT WITH HER!") << endl;

    return 0;
}

