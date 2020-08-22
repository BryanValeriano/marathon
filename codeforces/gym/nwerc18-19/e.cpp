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

#define NONE 0
#define SORT 1
#define SHUF 2

struct lista {
    vector<pair<int, vector<int>>> vs;
    void concat(lista& l) {
        int lastt = vs.back().first;
        for (auto& [t, v] : l.vs) {
            if (t == SHUF or lastt == SHUF) {
                vs.emplace_back(t, v);
                lastt = t;
            }
            else {
                lastt = vs.back().first = t & lastt and vs.back().second.back() < v[0];
                vs.back().second.insert(vs.back().second.end(), v.begin(), v.end());
            }
        }
    }
    void sort() {
        if (vs[0].first != SORT) {
            vs[0].first = SORT;
            if (vs.size() == 1) {
                std::sort(vs[0].second.begin(), vs[0].second.end());
            }
            else {
                multiset<int> s;
                for (auto& [t, v] : vs) {
                    for (int& x : v) {
                        s.insert(x);
                    }
                }
                vs.clear();
                vs.emplace_back(SORT, vector<int>(s.begin(), s.end()));
            }
        }
    }
    void shuffle() {
        if (vs[0].second.size() == 1) return;
        sort();
        vs[0].first = SHUF;
    }
    bool operator==(const lista& l) const {
        return vs == l.vs;
    }
};

pair<bool, vector<int>> parseList(string& s, int& pos) {
    vector<int> l;
    int x = 0, qtd = 0;
    bool issorted = true;
    for (;;pos++) {
        if (isdigit(s[pos])) {
            x *= 10;
            x += s[pos] - '0';
        }
        else {
            if (qtd and x < l.back()) {
                issorted = false;
            }
            l.push_back(x);
            qtd++;
            x = 0;
            if (s[pos] == ']') {
                return make_pair(issorted, l);
            }
        }
    }
}

lista parse(string& s, int& pos) {
    lista l;
    vector<lista> args(2);
    string com = "";
    for (;;pos++) {
        if (isalpha(s[pos])) {
            com += s[pos];
        }
        else if (s[pos] == ',') {
            pos++;
            args[1] = parse(s, pos);
        }
        else if (s[pos] == '(') {
            pos++;
            args[0] = parse(s, pos);
        }
        else if (s[pos] == ')' or !s[pos]) {
            if (com == "concat") {
                args[0].concat(args[1]);
            }
            else if (com == "shuffle") {
                args[0].shuffle();
            }
            else if (com == "sorted") {
                args[0].sort();
            }
            return args[0];
        }
        else if (s[pos] == '[') {
            pos++;
            auto [issorted, v] = parseList(s, pos);
            args[0].vs.emplace_back(issorted, v);
			return args[0];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;
    int n = 0, m = 0;
    lista x = parse(a, n);
    lista y = parse(b, m);
    cout << (x == y ? "equal" : "not equal") << endl;
    return 0;
}


