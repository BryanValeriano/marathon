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

bool isV(char i) {
    return (i == 'a' or i == 'e' or i == 'i' or i == 'u' or i == 'o' or i == 'y');
}

const int T = 102;
int n;
string s;
string ans;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;

    ans += s[0];
    for(int i = 1; i < n; i++) {
        if(isV(s[i]) and isV(s[i-1])) continue;
        ans += s[i]; 
    }

    cout << ans << endl;

    return 0;
}

