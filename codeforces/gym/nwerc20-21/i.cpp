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
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 410;
const int N = T;
int d[T];
int tmp[T];
int t[3][T];
ii table[3][T][T];
vii bag;
int n;

void pre(int a, int b) {
    int i = b;
    int time = 0;
    do {
        table[a][b][i] = mk(time,time+t[a][i]);
        time += t[a][i]+d[i];
        i++; i %= n;
    } while(i != b);
}

bool inter(ii a, ii b) {
    return !(a.fi >= b.se or a.se <= b.fi);
}

bool ok(int x, int y) {
    for(int i = 0; i < n; i++)
        if(inter(table[0][x][i], table[1][y][i]))
            return false;
    return true;
}

void bbAntes(int pessoa, int ini, int museu) {
    ii wat = table[pessoa][ini][museu];

    int l = 0;
    int r = n-1;
    int ans = -1;

    while(l <= r) {
        int mid = (l+r)>>1;
        int novo = (museu-mid+n)%n;
        ii x = table[2][novo][museu];
        if(x.se <= wat.fi) ans = mid, l = mid+1;
        else r = mid-1;
    }

    if(ans == -1) return;

    if(ans > museu) {
        tmp[0]++;
        tmp[museu+1]--;
        tmp[ans]++;
        tmp[n]--;
    } else {
        tmp[ans++];
        tmp[museu+1]--;
    }
}

void bbDepois(int pessoa, int ini, int museu) {
    ii wat = table[pessoa][ini][museu];

    int l = 0;
    int r = n-1;
    int ans = -1;

    while(l <= r) {
        int mid = (l+r)>>1;
        int novo = (museu-mid+n)%n;
        ii x = table[2][novo][museu];
        if(x.fi >= wat.se) ans = mid, r = mid-1;
        else l = mid+1;
    }

    if(ans == -1) return;

    if(ans > museu) {
        tmp[museu+1]++;
        tmp[ans+1]--;
    } else {
        tmp[0]++;
        tmp[ans+1]--;
        tmp[museu+1];
        tmp[n]--;
    }
}

int solve(int a, int b) {
    memset(tmp, 0, sizeof tmp);
    for(int i = 0; i < n; i++) {
        bbAntes(0,a,i);
        bbDepois(0,a,i);
        bbAntes(1,b,i);
        bbDepois(1,b,i);
    }

    for(int i = 0; i < n; i++) if(tmp[i] == 2*n) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> d[i];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < n; j++)
            cin >> t[i][j];

    for(int i = 0; i < 3; i++)
        for(int j = 0; j < n; j++)
            pre(i,j);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(ok(i,j)) bag.eb(i,j);

    for(ii x : bag) {
        int pos = solve(x.fi, x.se);
        if(pos >= 0) {
            cout << x.fi+1 << " " << x.se+1 << " " << pos+1 << endl;
            return 0;
        }
    }

    cout << "impossible\n";
    return 0;
}

