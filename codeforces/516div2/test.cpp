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
    cin.tie(NULL);
    cout.tie(NULL);
    int lim = 200;
    cout << lim << " " << lim << endl;
    cout << lim/2 << " " << lim/2 << endl;
    cout << lim << " " << lim << endl;
    for(int i = 1; i <= lim; i++) {
        for(int j = 1; j <= lim; j++) {
            cout << ".";
        }
        cout << endl;
    }
    return 0;
}

