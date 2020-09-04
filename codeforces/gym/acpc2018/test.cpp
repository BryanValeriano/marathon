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
const double LIM = 10e-7;
const double T = 1e4;

double calc(double x) {
    double ans = 0;
    double razao = 1;
    double area = 1;
    ll vez = 0;

    do {
        vez++;
        razao *= x;
        area -= razao;
        ans += area*T*vez;
        area = razao;
    }while(area*T*vez > LIM);

    return ans;
}

double fun(double x) {
    return (x/((1-x)*(1-x)));
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("baklava.in", "r", stdin);

    int t;
    cin >> t;
    for (int i = 0;i < t;i++) {
        int n;
        cin >> n;
        double alfa = PI - 2 * PI / n;
        double s = sin(alfa / 2);
        //cout << fixed << setprecision(5) << fun(s * s) * (1 - s * s) << endl;
        cout << fixed << setprecision(5) << calc(s*s) << endl;
    }

    return 0;
}

