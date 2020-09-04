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
double EPS = 1e-7;

double ele(double base, ll e) {
    double ans = 1;
    while(e) {
        if(e&1) ans *= base;
        base *= base;
        e >>= 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int s; cin >> s;
    while(s--) {
        int n; double gol; int pos;
        cin >> n >> gol >> pos;
        double allWrong = ele(1-gol,n);
        double first = ele(1-gol,pos-1)*gol;
        double acum = ele(1-gol,pos-1+n);
        while(acum*gol > EPS) {
            first += acum*gol;
            acum *= allWrong;
        }
        cout << fixed << setprecision(4) << first << endl;
    }
    return 0;
}

