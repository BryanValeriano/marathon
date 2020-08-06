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
const int T = 40;

int logg(int x) {
    int j = 1;
    int casa = 0;
    while(j < x) j <<= 1, casa++;
    return casa;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,q; cin >> n >> q;
    vector<int> bank(T,0);

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        bank[logg(x)]++;
    }

    while(q--) {
        int x; cin >> x;
        vector<int> tmp = bank;
        int ans = 0;
        bool ok = 1;

        for(int j = 1, casa = 0; j <= x; j<<=1,casa++) {
            if(x&j) {
                int need = 1;
                int have = 0;
                int used = 0;
                for(int k = casa; k >= 0 and need; k--) {
                    have += tmp[k];
                    used += tmp[k];
                    tmp[k] = 0;
                    if(have >= need) {
                        tmp[k] += have-need;
                        ans += used-tmp[k];
                        need = 0;
                        break;
                    }
                    need <<= 1;
                    have <<= 1;
                }
                if(need) {ok = 0; break;  }
            }
        }

        cout << (ok?ans:-1) << endl;
    }


    return 0;
}

