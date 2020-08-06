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

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    int saldo = 0;
    bool open = 0;
    for(int i = 0; i < n; i++) {
        saldo += (s[i]=='('?1:-1);
        if(saldo < 0) open = 1;
        if(open) {
            ans++;
            if(saldo == 0) open = 0;
        }
    }
    cout << (saldo==0?ans:-1) << endl;
    return 0;
}

