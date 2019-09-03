#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e4;

bitset<T> mat[T];
bitset<T> tmp;
int sqr;
int n;



int main() {
    ios::sync_with_stdio(false);
    //cin.tie(NULL); cout.tie(NULL);

    bool ok;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> ok;
            mat[i][j] = ok;
        }
    }

    int q; cin >> q;
    int op,x;

    while(q--) {
        cin >> op;
        if(op == 3) continue;
        else {
            cin >> x;
            x--;
       }
    }

    cout << endl;

    return 0;
}

