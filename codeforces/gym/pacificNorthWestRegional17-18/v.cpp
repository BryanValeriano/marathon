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
typedef pair<ii,string> ss;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct pqp {
    ii inter;
    string s;
    ii vals;
    pqp(ii inter, string s, ii vals) :
        inter(inter), s(s), vals(vals) {}

    bool operator == (const pqp &b) const {
        return (inter == b.inter and s == b.s and vals == b.vals);
    }
};

struct wat {
    vector<pqp> v;

    wat() {
        v.eb(mk(1,1234567890),"", mk(1,1234567890));
    }

    void ajust(int ini, int x) {
        for(int i = ini; i < v.size(); i++)
            v[i].inter.fi += x, v[i].inter.se += x;
    }

    void insert(int pos, string x) {
        for(int i = 0; i < v.size(); i++) {
            ii ok = v[i].inter;
            ii tc = v[i].vals;

            if(ok.fi <= pos and pos <= ok.se) {

                if(v[i].s != "") {
                    v.insert(v.begin()+i,pqp(mk(pos,pos), x, mk(0,0)));
                    ajust(i+1,1);
                    return;
                } else {
                    ll npos = tc.fi + pos-ok.fi;

                    ii left = mk(ok.fi,pos-1);
                    ii ll = mk(tc.fi,npos-1);
                    ii right = mk(pos+1,ok.se+1);
                    ii rr = mk(npos,tc.se);
                    int s = i;
                    if(left.fi <= left.se) v.insert(v.begin()+s, pqp(left, "",ll)), s++;
                    v.insert(v.begin()+s, pqp(mk(pos,pos), x, mk(0,0))), s++;
                    if(right.fi <= right.se) v.insert(v.begin()+s, pqp(right, "",rr)), s++;
                    v.erase(v.begin()+s);
                    ajust(s,1);
                    return;
                }
            }
        }
    }

    //void merge(int pos) {
    //    if(pos < 0) return;
    //    if(pos + 1 >= v.size()) return;
    //    ii x = v[pos].inter;
    //    ii y = v[pos+1].inter;
    //    if(x.se+1 == y.fi) {
    //        ii ok = mk(x.fi, y.se);
    //        v[pos+1].fi = ok;
    //        v.erase(v.begin()+pos);
    //    }
    //}

    void del(int pos) {
        return;
    //    int l = 1;
    //    int r = 0;
    //    for(int i = 0; i < v.size(); i++) {
    //        ii ok = v[i].fi;
    //        r += v[i].fi.se - v[i].fi.fi + 1;
    //        if(l <= pos and pos <= r) {
    //            pos = v[i].fi.fi + pos-l;
    //            if(v[i].se != "") {
    //                v.erase(v.begin()+i);
    //                ajust(i,-1);
    //                merge(i-1);
    //            } else {
    //                ii left = mk(ok.fi,pos-1);
    //                ii right = mk(pos+1,ok.se);
    //                int s = i;
    //                if(left.fi <= left.se) v.insert(v.begin()+s, ss(left, "")), s++;
    //                //v.insert(v.begin()+s, ss(mk(pos,pos), x)), s++;
    //                if(right.fi <= right.se) v.insert(v.begin()+s, ss(right, "")), s++;
    //                v.erase(v.begin()+s);
    //                ajust(s,-1);
    //                return;

    //            }
    //        }
    //        l = r+1;
    //    }
    }

    bool operator == (const wat &b) const {
        if(v.size() != b.v.size()) return false;
        for(int i = 0; i < v.size(); i++)
            if(!(v[i] == b.v[i])) return false;
        return true;
    }

    void print() {
        for(int i = 0; i < v.size(); i++) {
            cout << v[i].inter.fi << " , " << v[i].inter.se << " | " << v[i].s << " | ";
            cout << v[i].vals.fi << " " << v[i].vals.se << endl;
        }
    }
};

wat a[2];

void proc(int op) {
    char ok;
    string ko;
    int pos;
    a[op] = wat();
    cin >> ok;
    while(ok != 'E') {
        if(ok == 'D') {
            cin >> pos;
            a[op].del(pos);
        } else {
            cin >> pos >> ko;
            a[op].insert(pos,ko);
        }
        cin >> ok;
    }
        a[op].print();
        cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    proc(0);
    proc(1);
    cout << !(a[0] == a[1]) << endl;;
    return 0;
}

