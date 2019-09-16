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

const int T = 3e5 + 3;
int pos[T];
int num[T];
int n;
vector<ii> ans;

void troca(int x, int y) {
    int posx = pos[x];
    int posy = pos[y];
    ans.eb(posx,posy);
    swap(pos[x],pos[y]);
    swap(num[posx], num[posy]);
}

void troca2(int x, int y) {
    int posx = pos[x];
    int posy = pos[y];

    int ok = (posx-1) * 2 >= n? 1 : n;
    int ok2 = (n-posy) * 2 >= n? n : 1;

    int a = num[ok];
    int b = num[ok2];

    ans.eb(pos[x],ok);
    swap(pos[x],pos[a]);

    if(ok != ok2) {
        ans.eb(pos[x], ok2);
        swap(pos[x],pos[b]);
    }

    ans.eb(pos[x],pos[y]);
    swap(pos[x],pos[y]);

    num[pos[x]] = x;
    num[pos[y]] = y;
    num[pos[a]] = a;
    num[pos[b]] = b;
}

int main() {
    ios_base::sync_with_stdio(false);
    int x;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int x; cin >> x; pos[x] = i, num[i] = x;
    }

    for(int i = 2; i < n; i++) {
        if(pos[i] == i) continue;
        if(abs(pos[i] - i)*2 >= n) { troca(i,num[i]); }
        else troca2(i,num[i]);
    }

    if(pos[1] != 1) ans.eb(1,n), swap(pos[1], pos[n]);

    cout << ans.size() << endl;
    for(auto ok : ans) cout << ok.fi << " " << ok.se << endl;

    //for(int i = 1; i <= n; i++) cout << pos[i] << " ";
    //cout << endl;

    return 0;
}

