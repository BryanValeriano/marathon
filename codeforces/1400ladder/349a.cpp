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
    int v25 = 0;
    int v50 = 0;
    int v100 = 0;
    int n; cin >> n;
    int aux;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        if(aux == 25) v25++;
        if(aux == 50) { 
            if(v25) { v25--; v50++; }
            else flag = true;
        }
        if(aux == 100) {
            if(v50 and v25) { v50--; v25--; v100++; }
            else if(v25 >= 3) v25 -= 3;
            else flag = true;
        }
    }
    cout << (flag? "NO" : "YES") << endl;

    return 0;
}

