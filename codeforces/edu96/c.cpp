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
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        cout << 2 << endl;
        bool ok = 0;
        multiset<int> bag;
        for(int i = 1; i <= n; i++) bag.insert(i);
        for(int i = n-1; i > 0; i--) {
            int a = *bag.rbegin();
            bag.erase(bag.find(a));
            int b = *bag.rbegin();
            cout << a << " " << b << endl;
            bag.erase(bag.find(b));
            int k = ((a+b)>>1) + (a+b)%2;;
            bag.insert(k);
        }
    }


    return 0;
}

