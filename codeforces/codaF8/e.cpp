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

int main() {
    ios_base::sync_with_stdio(false);
    int x,k;
    cin >> x >> k;
    vii v;
    while(k--) {
        int op,a,b; cin >> op;
        cin >> a;
        if(op == 1) cin >> b;
        else b = a;
        v.eb(a,b);
    }

    v.eb(x,x);
    sort(v.begin(),v.end());
    int mini = 0, maxi = 0;
    int last = 0;

    for(int i = 0; i < v.size(); i++) {
        int gap = v[i].fi - last - 1;
        if(gap&1) mini++, maxi++, gap--;
        mini += gap/2;
        maxi += gap;
        last = v[i].se;
    }

    cout << mini << " " << maxi << endl;


    return 0;
}

