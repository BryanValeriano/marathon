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
    string s, rig, le; cin >> s;
    int k = s.size() - 1;
    while(s[k] == '0' and k > 0) k--;
    for(int i = 0; i <= k; i++)
        rig += s[i];
    for(int i = k; i >= 0; i--)
        le += s[i];
    cout << (rig == le? "YES" : "NO") << endl;

    return 0;
}

