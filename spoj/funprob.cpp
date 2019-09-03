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
    double n,m;
    double zero = 0;
    cin >> n >> m;
    while(n or m) {
        if(n > m) { 
            cout << fixed << setprecision(6) << zero << endl; 
            cin >> n >> m;
            continue; 
        }
        cout << fixed << setprecision(6) << (m-n+1)/((m+1)) << endl;
        cin >> n >> m;
    }
    return 0;
}

