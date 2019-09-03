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

const int T = 1e7 + 10;
bitset<T> crivo;
int v[T];

void init() {
    for(int i = 2; i < T; i++) {
        if(!crivo[i]) {
            for(int j = i+i; j < T; j += i) crivo[j] = 1;
        }
    }

    for(int i = 2; i < T; i++) {
        if(!crivo[i]) v[i] = i;
        else v[i] = v[i-1];
    }
}

int main() {
    init();
    int x;

    while(~scanf("%d\n", &x)) {
        int at = 8;
        int ans[4] = {2,2,2,2};
        if(x < 8) { printf("Impossible.\n"); continue; }
        for(int i = 0; i < 4; i++) {
            ans[i] = v[x-at+2]; 
            at += ans[i] - 2;
        }
        if(at == x) printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]); 
        else printf("Impossible.\n");
    }

    return 0;
}

