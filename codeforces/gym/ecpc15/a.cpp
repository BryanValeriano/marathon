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
const int T = 11;
const int N = 4e6;
const int LIM = 1e9;

unordered_map<int,int> id[T];
double ans[T][N];
int tot,casa;

int pega(const vector<int> &tmp) {
    int ans = 0;
    for(int i = tmp.size()-1, casa = 1; i >= 0; i--, casa*=10)
        ans += tmp[i]*casa;
    return ans;
}

int simple(int n) {
    int x = n;
    vector<int> tmp;
    while(x) tmp.pb(x%10), x /= 10;
    sort(tmp.begin(), tmp.end());
    int y = 0;
    int casa = 1;
    while(n) {
        int ok = lower_bound(tmp.begin(),tmp.end(),n%10) - tmp.begin();
        y += (ok+1)*casa;
        casa *= 10;
        n /= 10;
    }
    return y;
}

int gen(int n) {
    int x = n;
    casa = log10(n)+1;
    tot = id[casa].size();
    x = simple(n);
    return id[casa][x];
}

double prob(int pos) { return ans[casa][tot-pos]; }

void build(int x) {
    vector<int> v;
    for(int i = 1; i <= x; i++) v.pb(i);
    int pos = 1;
    do {
        int val = pega(v);
        id[x][val] = pos++;
    } while(next_permutation(v.begin(),v.end()));
}

void pre() {
    for(int i = 1; i <= 9; i++) {
        int sz = id[i].size();
        ans[i][0] = 0;
        double sum = 0;
        for(int j = 1; j <= sz; j++) {
            ans[i][j] += 1.0/sz + (1.0/sz)*sum;
            sum += ans[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(int i = 1; i <= 9; i++) build(i);
    pre();
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        if(n == LIM) { cout << 0 << endl; continue; }
        int pos = gen(n);
        cout << fixed << setprecision(9) << prob(pos) << endl;
    }
    return 0;
}

