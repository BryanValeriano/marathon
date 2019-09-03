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

const int T = 3e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    int n; string s, t;
    cin >> n >> s;
    t = s;
    
    int saldo = 0;
    int acum = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] == '(') saldo++;
        else if(s[i] == ')') saldo--;
        else t[i] = '(', saldo++;
    }


    for(int i = n-1; i >= 0; i--)
        if(s[i] == '?' and saldo - (acum+2) >= 0) t[i] = ')', acum += 2;
        
    acum = 0;

    for(int i = 0; i < n; i++) {
        if(t[i] == '(') acum++;
        else acum--;
        if(acum < 0 or (acum == 0 and i != n-1)) { cout << ":(" << endl; return 0; }
    }
    
    cout << (!acum? t : ":(") << endl;

    return 0;
}

