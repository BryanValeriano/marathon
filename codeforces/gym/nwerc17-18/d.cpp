#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define loop(x) for (int i = 0;i < x;i++)
#define each(x, xs) for (auto& x : xs)
#define iter(a) a.begin(), a.end()

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    map<string, pair<ll, ll>> cnt;
    map<string, string> tr;
    cin >> n;
    vector<string> d(n);
    loop(n) cin >> d[i];
    cin >> m;
    string dut, eng, cor;
    loop(m) {
        cin >> dut >> eng >> cor;
        if (cor == "correct") {
            cnt[dut].fi++;
            tr[dut] = eng;
        }
        else {
            if (tr[dut] == "") tr[dut] = eng;
        }
        cnt[dut].se++;
    }
    ll corr = 1, tot = 1;
    each(s, d) {
        ll c, t;
        tie(c, t) = cnt[s];
        corr *= c;
        tot *= t;
    }
    ll inc = tot - corr;
    if (tot == 1) {
        each(s, d) cout << tr[s] << " ";
        cout << endl;
        cout << (corr ? "correct" : "incorrect") << endl;
    }
    else {
        cout << corr << " correct" << endl;
        cout << inc  << " incorrect" << endl;
    }
