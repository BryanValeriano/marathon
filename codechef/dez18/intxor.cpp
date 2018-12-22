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
const int T = 5e4 + 100;
int ans[T];
int n;

int ask(int a, int b, int c) {
    int x;
    printf("1 %d %d %d\n", a, b, c);
    fflush(stdout);
    scanf("%d", &x);
    return x;
}

void find4(int a, int b, int c, int d) {
    ll um, dois, tres, quatro;
    um = ask(a,b,c);
    dois = ask(b,c,d);
    tres = ask(a,b,d);
    quatro = ask(a,c,d);

    ans[a] = um ^ tres ^ quatro;
    ans[b] = um ^ dois ^ tres;
    ans[c] = um ^ dois ^ quatro;
    ans[d] = dois ^ tres ^ quatro;
}

void find() {
    int i = 1;
    while(; n-(i+3) >= 4; i += 4) 
        find4(i, i+1, i+2, i+3);
    int last = i-1;
    if(n - i == 4) find4(i+1, i+2, i+3, i+4);

}

void print() {
    printf("2 ");
    for(int i = 1; i < n; i++) 
        printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
    fflush(stdout);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        find();
        print();
        int tmp; scanf("%d", &tmp);
        if(tmp == -1) return 0;
    }
    return 0;
}

