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
const int T = 1e5 + 5;

set<ii> bag;
ll top;
ll lft;
ll bot;
ll rig;
ll n,m,k,need;

int mov[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

bool isIn(int i, int j) {
    return (i >= 1 and i <= n and j >= 1 and j <= m and !bag.count(mk(i,j)));
}

int tenta(int i, int j, int pos, int vez) {
    if(pos == 4 and vez == 1) return 0;
    if(pos == 4) pos = 0, vez = 1;
    bag.emplace(i,j);
    cout << i << " " << j << endl;

    int ii = i + mov[pos][0];
    int jj = j + mov[pos][1];

    int ans = 1;

    if(isIn(ii,jj)) ans += tenta(ii,jj,pos,vez);
    else ans += max(tenta(i,j,pos+1,vez)-1,0); 

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    top = lft = INF;
    cin >> n >> m >> k;

    for(int i = 0; i < k; i++) {
        ll x,y; cin >> x >> y;
        bag.emplace(x,y);
        top = min(x,top);
        lft = min(y,lft);
        bot = max(x,bot);
        rig = max(y,rig);
    }

    need = n*m -k;

    bool ok = (tenta(1,1,0,0) == need);

    if(bag.count(mk(top,lft)) and bag.count(mk(bot,rig)))
        if(k == (bot-top+1)*(rig-lft+1))
            if(top == m - rig and m - rig == n - bot
                and n - bot == lft and lft == top)
                    ok = 1;

    cout << (ok == 1? "Yes" : "No") << endl; 
    return 0;
}

