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
const int LIM = 2e4;

int a,b,c;

int calc(int i, int j, int k) {
    return abs(i-a) + abs(b-j) + abs(c-k);
}

int main() {
    ios_base::sync_with_stdio(false);
    int ra,rb,rc;
    int tc; cin >> tc;

    while(tc--) {
        cin >> a >> b >> c;
        int best = INF;

        for(int i = 1; i < LIM; i++)
            for(int j = i; j < LIM; j += i)
                for(int k = j; k < LIM; k += j) {
                    int tmp = calc(i,j,k);
                    if(tmp < best) {
                        best = tmp;
                        ra = i, rb = j, rc = k;
                    }
                }

        cout << best << endl;
        cout << ra << " " << rb << " " << rc << endl;
    }

    return 0;
}

