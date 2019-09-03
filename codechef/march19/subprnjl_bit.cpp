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

const int T = 2e3 + 3;
const int LOG = 11;
int v[T];
int bit[T];
int ans;
int aparece[T];

void update(int pos, int val) {
    for(; pos < T; pos += pos&-pos) bit[pos] += val;
}

int search(int v) {
    int sum = 0;
    int pos = 0;

    for(int i = LOG; i >= 0; i--) {
        if(pos + (1<<i) < T and sum + bit[pos + (1<<i)] < v) {
            sum += bit[pos + (1<<i)];
            pos += (1<<i);
        }
    }

    return pos+1;
}

void test(int i, int j, int k) {
    int m = k/(j-i+1);
    if(k % (j-i+1) != 0) m++;
    int pos = k/m;
    if(k % m != 0) pos++;
    int kth = search(pos);
    if(aparece[aparece[kth]]) {
        ans++;
    }
}


int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int n,k; scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++) scanf("%d", v+i);
        int j = 1;
        ans = 0;
        for(int i = 1; i <= n; i++) {
            if(i & 1) {
                for(j = i; j <= n; j++) {
                    update(v[j],1);
                    aparece[v[j]]++;;
                    test(i,j,k);
                }
                update(v[i],-1);
                aparece[v[i]]--;
            } else {
                for(j = n; j >= i; j--) {
                    test(i,j,k);
                    update(v[j], - 1);
                    aparece[v[j]]--;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

