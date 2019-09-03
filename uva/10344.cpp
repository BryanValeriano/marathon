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

int v[6];
int ve[6];

bool can(int pos, int val) {
    if(pos == 4) return (val == 23);

    bool ans = false;

    ans |= can(pos+1, val + v[pos+1]);
    ans |= can(pos+1, val - v[pos+1]);
    ans |= can(pos+1, val * v[pos+1]);

    return ans;
}

bool ord(int pos, int mask) {
    if(pos == 5) return can(0,v[0]);
    
    bool ans = false;

    for(int i = 0; i < 5; i++) {
        if(!(mask & (1<<i))) {
            v[pos] = ve[i];
            ans |= ord(pos+1, mask | (1<<i));
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    for(int i = 0; i < 5; i++) cin >> ve[i];
    
    while(ve[0] or ve[1] or ve[2] or ve[3] or ve[4]) {
        cout << (ord(0,0)? "Possible" : "Impossible") << endl;
        for(int i = 0; i < 5; i++) cin >> ve[i];
    }

    return 0;
}

