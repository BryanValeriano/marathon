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
    cout << 1e3 << " " << 1e3 << " " << 1e3*1e3 << endl;
    ios::sync_with_stdio(false);
    for(int i = 1; i <= 1e3; i++) {
        for(int j = 1; j <= 1e3; j++) {
            cout << '.';
        }
        cout << endl;
    }
    for(int i = 1; i <= 1e3; i++) 
        for(int j = 1; j <= 1e3; j++) 
            cout << i << " " << j << endl;

    return 0;
}

