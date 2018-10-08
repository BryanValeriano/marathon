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
    string s; cin >> s;
    vector<int>row;
    for(int i = 0; i < s.size(); i++) 
        if(s[i] != '+') row.pb(s[i] - '0');
    sort(row.begin(), row.end());
    for(int i = 0; i < row.size(); i++) {
        cout << row[i];
        if(i + 1 < row.size()) cout << '+';
    }
    cout << endl;

    return 0;
}

