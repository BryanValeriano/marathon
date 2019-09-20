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
    int s; cin >> s;

    cout << s << ":" << endl;
    for(int i = 1; i < s; i++) {
        for(int j = i; j <= i+1 and j < s; j++) {
            if(i == j and i == 1) continue;
            int ok = s;
            bool passo = 0;
            while(ok > 0) {
                if(passo) ok -= min(i,j);
                else ok -= max(i,j);
                passo = !passo;
            }
            if(ok == 0) cout << max(i,j) << "," << min(i,j) << endl;
        }
    }

    return 0;
}

