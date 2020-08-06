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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int x = c/b + (c%b?1:0);
    int y = a/d + (a%d?1:0);
    cout << (x<=y?"Yes":"No") << endl;
    return 0;
}

