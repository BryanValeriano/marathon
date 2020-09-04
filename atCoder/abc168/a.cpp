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

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    if(n) n = n%10;
    if(n==3) cout << "bon\n";
    else if(n == 0 or n == 1 or n == 6 or n == 8) cout << "pon\n";
    else cout << "hon\n";
    return 0;
}

