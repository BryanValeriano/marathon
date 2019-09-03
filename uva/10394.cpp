#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 2e7 + 3;
bitset<T> crivo;
vii ans;

void init() {
    crivo[0] = crivo[1] = 1;
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            if(!crivo[i-2]) ans.eb(i-2,i);
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }
}

int main() {
    init();
    int x;

    while(~scanf("%d\n", &x))
        printf("(%d, %d)\n", ans[x-1].fi, ans[x-1].se);

    return 0;
}

