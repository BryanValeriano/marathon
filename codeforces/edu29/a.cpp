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
    string s; cin >> s;
    int k = s.size() - 1;
    while(s[k] == '0' and k >= 0) k--;
    string t;
    for(int i = 0; i <= k; i++) t += s[i];
    int x = 0;
    int y = t.size() - 1;
    int fim;
    if((int)t.size() & 1) fim == ((int)t.size()/2);
    else fim = (int)t.size()/2 - 1;
    while(x <= fim) {
        if(t[x] != t[y]) break;
        else { x++; y--; }
    }
    if(x-1 == fim and t[x-1] == t[y+1]) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

