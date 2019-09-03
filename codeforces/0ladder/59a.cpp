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
    string s;
    cin >> s;
    int g = 0;
    int p = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] < 97) g++;
    }
    p = s.size() - g;
    if(p >= g) transform(s.begin(), s.end(), s.begin(), ::tolower);
    else transform(s.begin(), s.end(), s.begin(), ::toupper);
    cout << s << endl;

    return 0;
}

