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
    string s;
    string t;
    cin >> s;
    int x = s.size();
    int ini;
    if(x % 2 == 0) ini = (int)s.size()/2 - 1;
    else ini = (int)s.size()/2;
    t = s[ini];
    if(ini + 1 < s.size()) t += s[ini+1];
    int left = ini-1;
    int right = ini+2;
    while(left >= 0 and right < s.size()) {
        t += s[left];
        t += s[right];
        left--;
        right++;
    }
    if(left == 0) t += s[left];
    if(right == s.size() - 1) t += s[right];
    cout << t << endl; 
    return 0;
}

