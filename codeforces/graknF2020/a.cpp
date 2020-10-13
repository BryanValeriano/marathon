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
const int T = 102;
int a[3][T], b [T], c[T];


int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < n; j++)
                cin >> a[i][j];

        int last = -1;
        int first = -1;
        for(int j = 0; j < n; j++) {
            for(int i = 0; i < 3; i++) {
                if(j != n-1 and a[i][j] != last) {
                    if(last==-1) first = a[i][j];
                    last = a[i][j];
                    cout << a[i][j] << " ";
                    break;
                }
                else if(j == n-1 and a[i][j] != last and a[i][j] != first) {
                    cout << a[i][j] << " ";
                    break;

                }
            }
        }
        cout << endl;
    }
    return 0;
}

