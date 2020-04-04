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

class ANDEquation {
    public:

    int restoreY(vector<int> A) {
        int n = A.size();
        for(int i = 0; i < n; i++) {
            int ans = A[i];
            int tmp = -1;
            for(int j = 0; j < n; j++) {
                if(j == i) continue;
                if(tmp == -1) tmp = A[j];
                else tmp &= A[j];
            }
            if(ans == tmp) return ans;
        }
        return -1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    ANDEquation x;
    cout << x.restoreY({1,3,5}) << endl;
    cout << x.restoreY({31,7}) << endl;
    cout << x.restoreY({31,7,7}) << endl;
    cout << x.restoreY(     	{191411,256951,191411,191411,191411,256951,195507,191411,192435,191411,
 191411,195511,191419,191411,256947,191415,191475,195579,191415,191411,
 191483,191411,191419,191475,256947,191411,191411,191411,191419,256947,
 191411,191411,191411}) << endl;

    return 0;
}

