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
const int T = 1e5 + 3;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string s;
    cin >> s;
    int silver = 0;
    int lastIni = INF;
    int maxi = 0;
    int ini = INF;
    bool flag = false;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'G') flag = true;
        if(s[i] == 'S'){
            silver++;
            if(silver > 1) ini = lastIni;
        }
        if(s[i] == 'G' and i == 0) { ini = 0; lastIni = 0; }
        if(s[i] == 'G' and i != 0 and s[i-1] == 'S') lastIni = i; 
        if(s[i] == 'S' and i != 0 and s[i-1] == 'S') { ini = i; lastIni = i; }
        maxi = max(maxi, i - ini + 1);
    }
    int maxi2 = 0;
    int cont = 0;
    if(s[0] == 'G') { v[0] = 1; cont++; }
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == 'G') cont++;
        if(s[i] == 'G' and s[i-1] == 'S') v[i] = 1;
        if(s[i] == 'G' and s[i-1] == 'G') v[i] = v[i-1] + 1;
        if(s[i] == 'S') v[i] = 0;
        maxi2 = max(maxi2, v[i]);
    }
    if(cont != (maxi-1)) cout << (flag? maxi : 0) << endl;
    else cout << maxi2 << endl;


    return 0;
}

