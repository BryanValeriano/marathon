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

struct subm {
    char c;
    int a, t;
    subm(char c, int a, int t) : c(c), a(a), t(t) {}
};

struct team {
    string name;
    vector<subm> ss;
    int score, pen, fac;

    team(string n) : name(n), score(0), pen(0), fac(INF) {}
    void add(char c, int a, int t) {
        ss.eb(c, a, t);
        if (c == '+') {
            score++;
            pen += t + (a - 1) * 20;
        }
        fac = min(fac, t);
    }
    void update(int id, char c, int a, int t) {
        if (ss[id].a != a) {
            if (ss[id].c != '+' and c == '+') {
                fac = min(t,fac);
                score++;
                pen += t + (a - 1) * 20;
            }
        }
    }
    bool operator<(team& t) {
        if (score != t.score) return score > t.score;
        if (pen != t.pen) return pen < t.pen;
        if (fac != t.fac) return fac < t.fac;
        return name < t.name;
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    int n, m, k;
    string name;
    char c;
    int a, t;
    cin >> n >> m >> k;
    vector<team> ts;
    for (int i = 0;i < m;i++) {
        cin >> name;
        ts.eb(name);
        for (int j = 0;j < n;j++) {
            cin >> c >> a >> t;
            ts[i].add(c, a, t);
        }
    }
    vector<team> leak;
    for (int i = 0;i < k;i++) {
        cin >> name;
        leak.eb(name);
        int id = 0;
        for (;ts[id].name != name;id++);
        for (int j = 0;j < n;j++) {
            cin >> c >> a >> t;
            leak[i].add(c, a, t);
            ts[id].update(j, c, a, t);
        }
    }
    sort(ts.begin(), ts.end());
    int id = 0;
    for (;ts[id].name != leak[0].name;id++);
    bool p = true;
    for (int i = 0;i < k and p;i++) {
        if (i + id >= m) {
            p = false;
            break;
        }
        if (leak[i].name != ts[i + id].name) p = false;
    }
    bool q = false;
    //for (int i = 0;i < k and q;i++) {
    //    if (id - i < 0) {
    //        q = false;
    //        break;
    //    }
    //    if (leak[i].name != ts[id - i].name) q = false;
    //}

    cout << (p || q ? "Leaked" : "Fake") << endl;
    return 0;
}

