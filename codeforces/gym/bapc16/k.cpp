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
const int T = 10;

int maxD(int x, int t) {
    int ans = 0;
    for(int i = 0; i < t; i++) {
        if(!(x&(1<<i))) continue;
        for(int j = 1; j <= t; j++) {
            int k = (i+j)%t;
            if(x&(1<<k)) {
                ans = max(ans,j);
                break;
            }
        }
    }
    return ans;
}

int solve(int dist, int t) {
    int gol = (1<<t);
    int ans = 0;

    for(int i = 1; i < gol; i++) {
        ans += (maxD(i,t) <= dist);
        //bitset<3> x(i);
        //cout << i << " | " << x << " = " << maxD(i,t) << endl;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    for(int i = 1; i <= T; i++) {
        for(int j = 1; j <= i; j++) {
            int x = solve(j,i);
            cout << i << " " << j << " = " << x << endl;
        }
    }
    return 0;
}

