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

const int T  = 2e5 + 10;
int X[T];
int Y[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    while(n) {
        for(int i = 0; i < n; i++) cin >> X[i] >> Y[i];
        int xx = X[n/2];
        int yy = Y[n/2];
        int s = 0;
        int o = 0;
        for(int i = 0; i < n; i++) {
            if(X[i] > xx and Y[i] > yy) s++;
            else if(X[i] < xx and Y[i] < yy) s++;
            else if(X[i] > xx and Y[i] < yy) o++;
            else if(X[i] < xx and Y[i] > yy) o++;
        }

        cout << s << " " << o << endl;
        cin >> n;
    }
    return 0;
}

