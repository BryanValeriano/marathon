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
double eps = 1e-9;

int main() {
    ios_base::sync_with_stdio(false);
    ll d,t,s; cin >> d >> t >> s;
    d = d/s + (d%s?1:0);
    cout << (d <= t? "Yes\n" : "No\n");
    return 0;
}

