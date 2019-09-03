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

const int T = 5e4 + 2;
const int blk = sqrt(T) + 3;

vector<tuple<int, int, int, int> > que[T];
int v[T];
int freq[T];
int mod[blk][blk];
int ans[T];
int n, q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int l,r,m,x,id;

    cin >> n >> q;
    for(int i = 1; i <= n; i++) cin >> v[i];

    for(int i = 0; i < q; i++) {
        cin >> l >> r >> x >> m;
        que[l-1].eb(m,x,-1,i);
        que[r].eb(m,x,1,i);
    }

    for(int i = 1; i <= n; i++) {
        freq[v[i]]++;
        for(int j = 1; j < blk; j++) mod[j][v[i]%j]++;
        for(int j = 0; j < que[i].size(); j++) {
            tie(m,x,l,id) = que[i][j];
            if(m < blk) ans[id] += l*mod[m][x];
            else for(int k = x; k < T; k += m) ans[id] += l*freq[k];
        }
    }

    for(int i = 0; i < q; i++) cout << ans[i] << endl;

    return 0;
}

