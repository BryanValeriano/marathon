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
const int T = 503;

int n,m, comido;
ll a[T];
ll b[T];

vector<pair<int,char>> res;

void erro() {
    cout << "NO" << endl;
    exit(0);
}

void come(vector<ii> &tmp, int x, int y) {
    tmp[x].fi += tmp[y].fi;
    for(int i = y; i < tmp.size(); i++) tmp[i].se--;
    tmp.erase(tmp.begin()+y);
}

bool canEat(vector<ii> &tmp, int id) {
    if(id - 1 >= 0 and tmp[id].fi > tmp[id-1].fi) return 1;
    else if(id + 1 < tmp.size() and tmp[id].fi > tmp[id+1].fi) return 1;
    return 0;
}

bool tent(int l, int r) {
    vector<ii> tmp;

    for(int i = l; i <= r; i++) tmp.eb(a[i],i-comido+1);

    while(tmp.size() > 1) {
        int maxi = -1;
        int id = -1;

        for(int i = 0; i < tmp.size(); i++)
            if(maxi < tmp[i].fi and canEat(tmp,i))
                maxi = tmp[i].fi, id = i;

        if(id == -1) return 0;

        if(id - 1 >= 0 and tmp[id].fi > tmp[id-1].fi) {
            res.eb(tmp[id].se,'L');
            come(tmp, id-1, id);
        }
        else if(id + 1 < tmp.size() and tmp[id].fi > tmp[id+1].fi) {
            res.eb(tmp[id].se,'R');
            come(tmp, id, id+1);
        }
        else return 0;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for(int i = 0; i < m; i++) cin >> b[i];

    int j = 0, i = 0;
    int last = 0, ans = 0;

    ll sum = 0;

    for(; j < n and i < m; j++) {
        sum += a[j];
        if(sum > b[i]) erro();
        else if(sum == b[i]) {
            if(!tent(last,j)) erro();
            comido += j-last;
            sum = 0;
            last = j+1;
            i++;
            ans++;
        }
    }

    if(ans != m or last != n) erro();

    cout << "YES" << endl;
    for(auto x : res) cout << x.fi << " " << x.se << endl;

    return 0;
}

