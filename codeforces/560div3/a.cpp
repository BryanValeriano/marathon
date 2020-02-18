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
    ios_base::sync_with_stdio(false);
    int n,x,y; cin >> n >> x >> y;
    string s; cin >> s;
    reverse(s.begin(), s.end());
    
    int ans = 0;
    for(int i = 0; i < y; i++) ans += s[i] == '1';
    ans += s[y] == '0';
    for(int i = y+1; i < x; i++) ans += s[i] == '1';

    cout << ans << endl; 
    
    return 0;
}

