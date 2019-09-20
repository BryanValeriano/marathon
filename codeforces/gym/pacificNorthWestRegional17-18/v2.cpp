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

struct wat {
    vector<ll> del;
    map<ll,char> ins;

    wat() {
        del.clear();
        ins.clear();
    }

    void add(ll pos, char y) {
        map<ll,char> aux;
        aux[pos] = y;
        for(auto z : ins) aux[z.fi + (z.fi >= pos)] = z.se;
        ins = aux;
    }

    void rem(ll pos) {
        if(ins.count(pos)) ins.erase(pos);
        else {
            ll p = pos;
            for(auto z : ins) p -= (z.fi < pos);
            sort(del.begin(),del.end());
            for(auto z : del) p += (z <= p);
            del.pb(p);
        }
        map<ll,char> aux;
        for(auto z : ins) aux[z.fi - (z.fi > pos)] = z.se;
        ins = aux;
    }


    bool operator == (const wat &b) const {
        return (del == b.del and ins == b.ins);
    }
};

wat a[2];

void proc(int op) {
    char x, y;
    ll pos;
    cin >> x;
    while(x != 'E') {
        cin >> pos;
        if(x == 'D') a[op].rem(pos);
        else cin >> y, a[op].add(pos,y);
        cin >> x;
    }
    sort(a[op].del.begin(), a[op].del.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    proc(0);
    proc(1);
    cout << !(a[0] == a[1]) << endl;
    return 0;
}

