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

const int T = 1e5 + 2;

string s;
bool v[T];
bool can[T];
bool ok[T];
int n;

bool solve(int t) {
    for(int i = 0; i < t; i++) ok[i] = 1;
    for(int i = 0; i < n; i++) ok[i%t] &= v[i];
    for(int i = 0; i < t; i++) if(ok[i]) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    int ans = 0;
    n = s.size();
    for(int i = 0; i < n; i++) v[i] = (s[i] == 'R');
    for(int i = 1; i < n; i++) if(n%i==0) can[i] = solve(i);
    for(int i = 1; i < n; i++) ans += can[__gcd(i,n)];
    cout << ans << endl;
    return 0;
}

