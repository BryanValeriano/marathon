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

typedef tuple<string, int, int> tup;

bool comp1(tup a, tup b) {
    return get<1>(a) < get<1>(b);
}

bool comp2(tup a, tup b) {
    return get<1>(a) > get<1>(b);
}

bool comp3(tup a, tup b) {
    return get<2>(a) > get<2>(b);
}

typedef bool (*fn)(tup, tup);

int main() {
    ios_base::sync_with_stdio(false);

    vector<fn> fns = {comp1, comp2, comp3};

    int n, q;
    cin >> n >> q;
    vector<tup> a;
    string s;
    int p, r;
    for (int i = 0;i < n;i++) {
        cin >>  s >> p >> r;
        a.emplace_back(s, p, r);
    }
    vector<vector<string>> ans(4);
    for (int i = 0;i < 4;i++) {
        if (i) sort(a.begin(), a.end(), fns[i - 1]);
        for (auto& [name, pr, re] : a) {
            ans[i].push_back(name);
        }
    }
    string op;
    int at = 0;
    for (int i = 0;i < q;i++) {
        cin >> op;
        if (op[0] == 'i') {
            int x;
            cin >> x;
            cout << ans[at][x - 1] << endl;
        }
        else if (op[8] == 'r') at = 3;
        else if (op[9] == 'a') at = 2;
        else at = 1;
    }
    return 0;
}

