#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
int v[T];
tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> s;
int ans;
int aparece[T];


void test(int i, int j, int k) {
    int m = k/(j-i+1);
    if(k % (j-i+1) != 0) m++;
    int pos = k/m;
    if(k % m != 0) pos++;
    int kth = *(s.find_by_order(pos-1));
    cout << i << " " << j << " " << k << " | " << pos << " " << kth << endl;
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
        s.clear();
        for(int i = 1; i <= n; i++) {
            if(i & 1) {
                for(j = i; j <= n; j++) {
                    s.insert(v[j]);
                    aparece[v[j]]++;;
                    test(i,j,k);
                }
                s.erase(s.lower_bound(v[i]-1));
                aparece[v[i]]--;
            } else {
                for(j = n; j >= i; j--) {
                    test(i,j,k);
                    s.erase(s.lower_bound(v[j]-1));
                    aparece[v[j]]--;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

