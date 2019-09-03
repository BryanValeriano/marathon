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
    int n,k;
    cin >> n >> k;

    if(k == 1) {
        cout << 0;
        for(int i = 1; i < n; i++) cout << 1;
        cout << endl;
    }

    else if(k == n) {
        for(int i = 0; i < n; i++) cout << 0;
        cout << endl;
    }

    else if(k > (n/2)) {
        for(int i = 1; i <= n; i++) {
            if(i&1) cout << 0;
            else cout << 1;
        }
        cout << endl;
    }

    else if((k == (n/2) and (!(n&1))) or (k == 2)) {
        for(int i = 1; i <= n; i++) {
            if(i <= n/2) cout << 0;
            else cout << 1;
        }
        cout << endl;
    }

    else if(k < (n/2)  + (n&1)) {
        string x = "011";
        for(int i = 0; i < n; i++) cout << x[i%3];
        cout << endl;
    }

    
    
    return 0;
}

