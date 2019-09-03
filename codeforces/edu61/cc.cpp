#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

#define MAX 5000

struct painter {
    int l, r, c;
};

int n;
int q;
painter p[MAX+10];
int fence[MAX+10];

int main (void) {
	ios_base::sync_with_stdio(false);

    memset(fence, 0, sizeof fence);

    scanf("%d %d", &n, &q);
    for(int i = 1; i <= q; i++) {
        scanf("%d %d", &(p[i].l), &(p[i].r));
        p[i].c = p[i].r-p[i].l+1;
    }

    for (int i = 1; i <= q-2; i++) {
        int c_max = 0;
        int i_max = 0;

        for(int j = i; j <= q; j++) {
            if(p[j].c >= c_max) {
                if(p[j].c > c_max || (p[j].l <= p[i_max].l && p[j].r >= p[i_max].r)) {
                    c_max = p[j].c;
                    i_max = j;
                }
            }
        }

        swap(p[i], p[i_max]);
        int l = p[i].l, r = p[i].r;

        for(int j = l; j <= r; j++) {
            fence[j] = 1;
        }

        for (int j = i+1; j <= q; j++) {
            if (p[j].l > r || p[j].r < l) continue;

            if (p[j].l >= l && p[j].r <= r) p[j].c = 0, p[j].l;

            if (p[j].l < l && p[j].r <= r) {
                p[j].c -= (p[j].r-l+1);
                p[j].r = l-1;
            }

            if (p[j].r > r && p[j].l >= l) {
                p[j].c -= (l-p[j].l+1);
                p[j].l = r+1;
            }
        }
    }

    int total = 0;
    for(int i = 1; i <= n; i++) {
        if(fence[i]) {
            total++;
        }
    }

    printf("%d\n", total);
	return 0;
}
