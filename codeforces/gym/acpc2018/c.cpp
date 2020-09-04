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

int main() {
    ios_base::sync_with_stdio(false);
    freopen("coffee.in", "r", stdin);

    int t;
    cin >> t;
    for (int i = 0;i < t;i++) {
        int c, p;
        cin >> c >> p;
        map<string, vector<int>> cs;
        string cafe;
        int s, m, l;
        int del = 100 / p;
        for (int i = 0;i < c;i++) {
            cin >> cafe >> s >> m >> l;
            cs[cafe] = {s, m, l};
        } 
        string name, type;
        for (int i = 0;i < p;i++) {
            cin >> name >> type >> cafe;
            int cost = cs[cafe][type[0] == 's' ? 0 : type[0] == 'm' ? 1 : 2] + del;
            if (cost % 5 == 1) cost--;
            else if (cost % 5 == 4) cost++;
            cout << name << " " << cost << endl;
        }
    }
    return 0;
}

