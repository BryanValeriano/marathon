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
const int T = 1e5 + 5;

int n;
int aux[T];
string s;


int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    int ans = 0;
    int um = 0, zero = 0;
    int op = 0;

    for(int i = 0; i < n; i++) {
        if(i and s[i] == s[i-1]) aux[i] |= 1;
        if(i < n-1 and s[i] == s[i+1]) aux[i] |= 2;
    }

    for(int i = 0; i < n; i++) {
        if(aux[i] & 1) op++;
        if(op == 1) s[i] = (s[i] == '0'? '1' : '0');
        if((aux[i] & 2) and op) op++;
    }


    //cout << s << endl;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') um = zero+1;
        else zero = um+1;
    }

    ans = max(um,zero); 
    cout << ans << endl;

    return 0;
}

