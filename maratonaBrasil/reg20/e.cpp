#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'
#define int ll

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int T = 1e5+2;
int ans[T], ans1[T], ans2[T];
int pai[T], maxi[T], idade[T], bit[T];
vector<int> sweep[T];
vector<int> sweep2[T];

bool isIn(int a, int b, int x, int y) {
    return (x >= a and y <= b);
}

int q(int x) {
    int s = 0;
	while(x > 0){
		s += bit[x];
		x -= (x & -x);
	}
    return s;
}

int query(int x) {
    return q(T-1) - q(x-1);
}

void update(int x, int v) {
    while(x < T){
        bit[x] += v;
		x += (x & -x);
	}
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    int n,k; cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> idade[i];
        cin >> pai[i];
        maxi[pai[i]] = max(maxi[pai[i]], idade[i]);
    }

    vii tmp;
    for(int i = 1; i <= n; i++) tmp.eb(idade[i],i);
    sort(tmp.begin(),tmp.end());

    for(int i = 0; i < k; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        ans[a]++;
        if(isIn(b,c,idade[a],(a == 1?-10:idade[pai[i]]))) ans[a]--;
        else if(isIn(b,c,idade[maxi[a]],idade[a])) ans[a]--;
        sweep[b].eb(c);
        sweep[c+1].eb(-c);
        sweep2[b].pb(b);
        sweep2[c+1].pb(-b);
    }

    int ok = 1;
    for(ii x : tmp) {
        while(ok <= x.fi) {
            for(int at : sweep[ok]) {
                if(at < 0) update(-at,-1);
                else update(at,1);
            }
            ok++;
        }
        if(x.se == 1) continue;
        ans1[x.se] += query(idade[pai[x.se]]);
    }

    memset(bit,0,sizeof bit);
    ok = 1;

    for(ii x : tmp) {
        while(ok <= x.fi) {
            for(int at : sweep2[ok]) {
                cout << at << " zzz  " << endl;
                if(at < 0) update(-at,-1);
                else update(at,1);
            }
            ok++;
        }
        cout << x.fi << " " << x.se << " | " << maxi[x.se] << " " << q(maxi[x.se]) << endl;
        ans2[x.se] += q(maxi[x.se]);
    }

    for(int i = 1; i <= n; i++) {
        cout << max(ans1[i],ans2[i]) + ans[i] << " ";
        cout << ans1[i] << " " << ans2[i] << " " << ans[i] << endl;
    }

    return 0;
}

