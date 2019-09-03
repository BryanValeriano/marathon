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

const int T = 2e5 + 5;

int n, k;
int v[T];

bool check(int x) {
    int tot = 0;
    int used = 0;

    for(int i = 0; i < n; i++) {
        if(v[i] <= tot) tot++;
        else if(v[i] > tot and used < x) tot++, used++;
    }

    return (tot >= k);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> v[i];

    int l = 0;
    int r = n;
    
    while(l <= r) {
        int mid = (l+r) >> 1;
        if(check(mid)) r = mid-1;
        else l = mid+1;
    }

    cout << l << endl;
    return 0;
}

