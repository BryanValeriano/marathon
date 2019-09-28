#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

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
const int T = 1e6 + 4;
const int LOGN = 20;

int bit[T];
priority_queue<ii, vii, greater<ii> > pq;

void add(int x, int v) {
    while(x < T) {
        bit[x] += v;
        x += (x&-x);
    }
}

int sch(int x) {
    int sum = 0;
    int pos = 0;

    for(int i = LOGN; i >= 0; i--) {
        if(pos + (1<<i) < T and sum + bit[pos + (1<<i)] < x) {
            sum += bit[pos + (1<<i)];
            pos += (1 << i);
        }
    }

    return pos+1;
}
 
int main() {
    int tc;
    scanf("%d", &tc);
    int cont = 0;

    while(tc--) {


        int op; int z; scanf("%d", &z);
        int time; int fim; int x;
        int sz = 0;
        printf("Case %d:\n", ++cont);

        while(z--) {
            scanf("%d", &op);
            scanf("%d %d", &time, &x);

            if(op == 1) {
                scanf("%d", &fim);
                pq.emplace(fim,x);
                add(x,1);
                sz++;
            } else {
                while(!pq.empty()) {
                    ii at = pq.top();
                    if(at.fi < time) {
                        add(at.se,-1);
                        pq.pop();
                        sz--;
                    } else break;
                }
                if(x > sz) printf("-1\n");
                else printf("%d\n", sch(x));
            }
        }

        while(pq.size()) {
            ii x = pq.top();
            add(x.se,-1), pq.pop();
        }

    }
    return 0;
}

