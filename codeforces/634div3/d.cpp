#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int mov[3][2] = { {0,0}, {1,3}, {2,6} };
char m[10][10];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cin >> m[i][j];
            }
        }
        for(int k = 0; k < 3; k++) {
            int i = mov[k][0];
            int j = mov[k][1];
            while(i < 9 and j < 9) {
                if(m[i][j]=='9') m[i][j] = '1';
                else m[i][j]++;
                i += 3;
                j++;
            }
        }
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << m[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}

