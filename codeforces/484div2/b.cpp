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

const int T = 2e5 + 10;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    priority_queue<ii, vii > ext;
    priority_queue<ii, vii, greater<ii> > intr;
    int n; cin >> n;
    int x;

    for(int i = 1; i <= n; i++) {
        cin >> x;
        intr.emplace(x,i);
    }

    char y;
    for(int i = 0; i < 2*n; i++) {
        cin >> y;
        if(y == '1') {
            cout << ext.top().se << " ";
            ext.pop();
        } else {
            cout << intr.top().se << " ";
            ext.emplace(intr.top());
            intr.pop();
        }
    }
    cout << endl;
    return 0;
}

