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

const int T = 505;
int g[T][T];
int r,c;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> r >> c;

    if(r == 1 or c == 1) {
        cout << 0 << endl;
        return 0;
    }

    for(int i = 1; i <= r; i++) {
        for(int j = r+1; j <= r+c; j++)  
            cout << i*j<< " ";
        cout << endl;
    }
    
    return 0;
}

