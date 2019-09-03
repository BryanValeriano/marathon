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
    string s,t,z;
    cin >> s >> t;
    int ini = -1, fim = -1;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != t[i]) {
            if(ini == -1) ini = fim = i;
            else fim = i;
        }
    }
    if(ini == -1) { cout << "YES" << endl; return 0; }
    for(int i = 0; i < ini; i++) z += s[i];
    for(int i = fim; i >= ini; i--) z += s[i];
    for(int i = fim+1; i < s.size(); i++) z += s[i];

    cout << (z == t? "YES" : "NO") << endl;

    return 0;
}

