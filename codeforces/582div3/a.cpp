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
    int a,b;
    a = 0; b = 0;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x&1) a++;
        else b++;
    }

    cout << min(a,b) << endl;



    return 0;
}

