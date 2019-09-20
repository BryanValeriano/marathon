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
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);
    int x,y,z,t1,t2,t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;

    int a = abs(x-y)*t1;
    int b = t3*3 + abs(x-y)*t2 + abs(x-z)*t2;

    cout << (b <= a? "YES" : "NO") << endl;

    return 0;
}

