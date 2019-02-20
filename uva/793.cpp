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
int pai[T];
int peso[T];

int find(int x) {
    return (x == pai[x]? x : pai[x] = find(pai[x]));
}

void join(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(peso[x] < peso[y]) swap(x,y);
    pai[y] = x;
    if(peso[x] == peso[y]) peso[x]++;
}

void reset() {
    for(int i = 0; i < T; i++) {
        pai[i] = i;
        peso[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    int n;
    int good = 0;
    int bad = 0;
    cin >> n;
    reset();
    while(true) {
        string oper;
        int a,b;
        if(cin >> oper) {
            if(oper == "c") {
                cin >> a >> b;
                join(a,b);
            }
            else if(oper == "q") {
                cin >> a >> b;
                (find(a) == find(b)? good++ : bad++);

            }
            else {
                cout << good << "," << bad << endl << endl;
                reset();
                good = bad = 0;
            }
        } 
        else break;
    }
    cout << good << "," << bad << endl;
    return 0;
}

