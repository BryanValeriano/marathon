#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    //ios::sync_with_stdio(false);
    int n; cin >> n;
    if(n == 3) {
        printf("%d %d %d\n", 1, 1, 3);
        return 0;
    }
    int lim;
    if(n&1) lim = n/2 + 1;
    else lim = n/2;
    for(int i = 0; i < lim; i++) 
        printf("%d ", 1);
    int teto = log2(n);
    for(int i = 0; i < (n/2)-teto; i+=2) 
        printf("%d ", 2);
    for(int i = 1; i < teto + 1; i++) {
        int x = pow(2,i);
        printf("%d ", x);
    }
    printf("\n");


    return 0;
}

