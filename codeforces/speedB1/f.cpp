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

const int T = 54;

unordered_set<string> dek;
string mat[T][T];
int n,m;
vector< pair< string, ii > > jok;
vii ans;

void build() {

    vector<string> tmp;
    vector<string> suit;

    tmp.pb("T");
    tmp.pb("Q");
    tmp.pb("J");
    tmp.pb("K");
    tmp.pb("A");

    suit.pb("C");
    suit.pb("D");
    suit.pb("H");
    suit.pb("S");

    for(int i = 0; i < tmp.size(); i++)
        for(int j = 0; j < suit.size(); j++)
            dek.insert(tmp[i] + suit[j]);

    for(char i = '2'; i <= '9'; i++)
        for(int j = 0; j < suit.size(); j++)
            dek.insert((string)(i + suit[j]));

}

void res() {
    cout << "Put the first square to (" << ans[0].fi << ", " << ans[0].se << ")." << endl;
    cout << "Put the second square to (" << ans[1].fi << ", " << ans[1].se << ")." << endl;
}

bool busc(string a, string b) {
    if(a != "") mat[jok[0].se.fi][jok[0].se.se] = a;
    if(b != "") mat[jok[1].se.fi][jok[1].se.se] = b;

    vii possible;

    for(int i = 1; i+2 <= n; i++) {
        for(int j = 1; j+2 <= m; j++) {
            unordered_set<char> suit;
            unordered_set<char> rank;
            for(int k = i; k <= i+2; k++) {
                for(int p = j; p <= j+2; p++) {
                    rank.insert(mat[k][p][0]);
                    suit.insert(mat[k][p][1]);
                }
            }

            if(suit.size() == 1 or rank.size() == 9) possible.eb(i,j);

        }
    }

    for(int i = 0; i < possible.size(); i++)
        for(int j = i+1; j < possible.size(); j++) {
            if((possible[i].fi + 2 < possible[j].fi or possible[j].fi + 2 < possible[i].fi) 
                    or (possible[i].se + 2 < possible[j].se or possible[j].se + 2 < possible[i].se)) {
                ans.pb(possible[i]);
                ans.pb(possible[j]);
                return 1;
            }
        }

    return 0;
}

void search(int qtd) {

    if(qtd == 0) {
        if(!busc("","")) cout << "No solution." << endl;
        else {
            cout << "Solution exists." << endl;
            cout << "There are no jokers." << endl;
            res();
        }
        return;
    }

    else if(qtd == 1) {
        for(auto x : dek) {
            if(busc(x,"")) {
                cout << "Solution exists." << endl;
                cout << "Replace " << jok[0].fi << " with " << x << "." << endl;
                res();
                return;
            }
        }
    }

    else {
        for(auto x : dek) {
            for(auto y : dek) {
                if(x == y) continue;
                if(busc(x,y)) {
                    cout << "Solution exists." << endl;
                    cout << "Replace " << jok[0].fi << " with " << x;
                    cout << " and " << jok[1].fi << " with " << y << "." << endl;
                    res();
                    return;
                }
            }
        }
    }

    cout << "No solution." << endl;
}

int main() {
    ios::sync_with_stdio(false);
    build();

    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) { 
            cin >> mat[i][j];
            if(mat[i][j] == "J1"  or mat[i][j] == "J2")
                jok.eb(mat[i][j],mk(i,j));
            dek.erase(mat[i][j]);
        }

    if(jok.size() == 2 and jok[0].fi == "J2") swap(jok[0],jok[1]);

    search(jok.size());

    return 0;
}

