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
const int T = 1e5+5;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int sqr = 0, rec = 0;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v[x]++;
        if(v[x]%4 == 0) sqr++;
        if(v[x]%2 == 0) rec++;
    }

    int q; cin >> q;
    while(q--) {
        char op; int x;
        cin >> op >> x;
        if(op == '+') {
            v[x]++;
            if(v[x]%4 == 0) sqr++;
            if(v[x]%2 == 0) rec++;
        } else {
            if(v[x]%4 == 0) sqr--;
            if(v[x]%2 == 0) rec--;
            v[x]--;
        }
        cout << (sqr and rec >= 4? "YES\n" : "NO\n");
    }


    return 0;
}

