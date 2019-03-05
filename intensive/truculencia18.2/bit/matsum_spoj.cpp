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

const int T = 1024 + 3;
int bit[T][T];
int mat[T][T];
int n;

void update(int x, int y, ll val) {
    for(; x <= n; x += (x & -x)) 
        for(int j = y; j <= n; j += (j & -j))
            bit[x][j] += val;
}

int query(int x, int y) {
    int sum = 0;
    for(; x; x -= (x & -x))
        for(int j = y; j ; j -= (j & -j))
            sum += bit[x][j];
    return sum;
}

int main() {
    int tc, x1, y1, x2, y2;
    string oper;
    char tmp[4];
    scanf("%d", &tc);
    while(tc--) {
        memset(bit, 0, sizeof bit);
        memset(mat, 0, sizeof mat);
        scanf("%d", &n);
        while(true) {
            scanf("%3s", tmp);
            oper = tmp;
            if(oper == "SET") {
                scanf("%d %d %d", &x1, &y1, &x2);
                x1++; y1++;
                update(x1,y1, -mat[x1][y1]);
                update(x1,y1, x2);
                mat[x1][y1] = x2;
            } 
            else if(oper == "SUM") {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                x1++; y1++; x2++; y2++;
                printf("%d\n", query(x2,y2) - query(x2,y1-1) - query(x1-1, y2) + query(x1-1,y1-1));
            } else { printf("\n"); break; }
        }
    }
    return 0;
}

