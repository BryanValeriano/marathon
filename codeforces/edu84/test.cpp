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
const int T = 15;
ll ans[T];
int n;
string test;

void calc() {
    int eq = 1;
    for(int i = 1; i < n; i++) {
        if(test[i] == test[i-1]) eq++;
        else {
            ans[eq]++;
            eq = 1;
        }
    }
    ans[eq]++;
}

void solve(int casa) {
    if(casa == n) { calc(); return; }
    for(char i = '0'; i <= '9'; i++) {
        test[casa] = i;
        solve(casa+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) test += '0';
    solve(0);
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}

