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

const int T = 102;

int n,m,k;
int v[T];

int main() {
    ios_base::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m >> k;
        for(int i = 0; i < n; i++) cin >> v[i];

        bool flag = 0;

        for(int i = 0; i < n-1; i++) {
            int tira = max(0,v[i] - max(0,(v[i+1]-k)));
            v[i] -= tira;
            m += tira;

            if(v[i]+k < v[i+1]) {
                int precisa = v[i+1] - (v[i]+k);
                if(precisa > m) {
                    cout << "NO" << endl;
                    flag = 1;
                    break;
                } else m -= precisa;
            }

        }

        if(!flag) cout << "YES" << endl;

    }



    return 0;
}

