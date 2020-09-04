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
const double LIM = 10e-5;
const double T = 1e4;

double calc(double base) {
    double ans = 0;
    double razao = 1;
    double b = 1;
    ll vez = 0;

    do {
        vez++;
        b *= base;
        razao = (1/b);
        ans += razao*T*vez;
    }while(razao*T*vez > LIM);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("baklava.in", "r", stdin);

    cout << calc(4) << endl;
    return 0;
}

