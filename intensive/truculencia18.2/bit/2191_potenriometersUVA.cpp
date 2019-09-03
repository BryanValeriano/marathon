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
ll bit[T];
ll v[T];

void update(int pos, ll val) {
    for(; pos < T; pos += (pos & -pos)) bit[pos] += val;
}

ll query(int pos) {
    ll sum = 0;
    for(; pos; pos -= (pos & -pos)) sum += bit[pos];
    return sum;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,a,b,cont;
    string oper;
    cont = 0;
    cin >> n;
    while(n) {
        memset(bit, 0, sizeof bit);
        for(int i = 1; i <= n; i++) cin >> v[i], update(i,v[i]);
        cout << "Case " << ++cont << ":" << endl;
        while(true) {
            cin >> oper;
            if(oper == "END") { cin >> n; if(n)cout << endl; break; }
            cin >> a >> b;
            if(oper == "M") cout << query(b) - query(a-1) << endl;
            else update(a, b - v[a]), v[a] = b; 
        }
    }
    return 0;
}

