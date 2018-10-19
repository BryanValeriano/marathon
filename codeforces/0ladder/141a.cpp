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
    string s, t, v;
    cin >> s >> t >> v;
    s += t;
    if(s.size() != v.size()) { cout << "NO" << endl; return 0; }
    sort(s.begin(), s.end());
    sort(v.begin(), v.end());
    for(int i = 0; i < s.size(); i++) 
        if(s[i] != v[i]) 
            { cout << "NO" << endl; return 0; }

    cout << "YES" << endl;
    return 0;
}

