#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e5 + 5;
const int N = 22;

int v[T][N];
unordered_set<int> bag;
unordered_map<int,int> dp;
int n;

int num(int r, int l) {
    int x = 0;
    for(int i = 0; i < N; i++)
        if(v[r][i] - v[l][i]) x |= (1 << i);
    return x;
}

int nextDif(int l, int fst) {
    int x = num(l,fst);
    int r = n;
    int ans = n+1;

    while(l <= r) {
        int mid = (l+r) >> 1;
        if(num(mid,fst) != x) r = mid-1, ans = mid;
        else l = mid+1;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        for(int j = 0; j < N; j++) {
            if(x & (1 << j)) v[i][j]++;
            v[i][j] += v[i-1][j];
        }
        bag.insert(x);
    }

    int i = 1;

    while(i <= n) {
        int l = i;

        while(l <= n) {
            int x = num(l,i-1);
            bag.insert(x);

            if(dp.count(x) and dp[x] > l) l = dp[x];
            else dp[x] = l = nextDif(l,i-1);
        }

        i++;
    }

    cout << bag.size() << endl;

    return 0;
}

