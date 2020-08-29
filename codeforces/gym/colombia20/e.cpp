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

void query(int x) {
    cout << x << endl;
    cout.flush();
}

int main() {
    int depth; cin >> depth;
    query(1);
    int dist, ndist;
    cin >> dist;
    int last = 1;
    while(dist) {
        query(2*last);
        cin >> ndist;
        last = (ndist < dist? 2*last : 2*last+1);
        dist = (ndist < dist? ndist : dist-1);
    }
    cout << "! " << last << endl;
    cout.flush();
    return 0;
}

