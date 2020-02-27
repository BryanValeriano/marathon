#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
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
const int T = 2e6 + 5;
int v[T];
int ans[T];
int tmp[T];

int main() {
    ios_base::sync_with_stdio(false);
    int d = 0;
    int diff = 0;
    int ord = 0;
    int last = -1;

    int n,m; cin >> n >> m;

    for(int i = 0; i < n; i++) tmp[i] = v[i] = i+1;

    while(m--) {
        int op, x;
        cin >> op;
        if(op == 1) {
            cin >> x;
            d += x;
        } else {
            if(!diff) {
                if(abs(d)&1) ord = last = 1;
                else ord = last = 0;
                diff++;
            } else {
                if((abs(d)&1) == last) diff--;
                else diff++;
                last = !last;
            }
        }

        d = (d + n) % n;
    }

    //cout << diff << " " << last << " " << d << endl;

    if(diff) {
        for(int i = 0; i < n; i++) {
            int gol = (ord? (i&1? (i+diff)%n : (i-diff+n)%n) :
                    (i&1? (i-diff+n)%n : (i+diff)%n) );
            tmp[gol] = v[i];
        }
    }


    //for(int i = 0; i < n; i++) cout << tmp[i] << " ";
    //cout << endl;

    for(int i = 0; i < n; i++) ans[(i+d+n)%n] = tmp[i];
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}

