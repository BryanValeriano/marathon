#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt_rand(seed);


typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
int N = 1e5;

int main() {
    ios_base::sync_with_stdio(false);
    cout << N << " " << 1 << " " << 1 << " " << 1 << endl;
    while(N--) {
        int x = (mt_rand()%3)+1;
        cout << (char)('A' + x) << " ";
        int y = (mt_rand()%3)+1;
        cout << (char)('A' + y) << endl;
    }
    return 0;
}

