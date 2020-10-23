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
const int N = 15;
const int T = (1<<N);

bool dp[T][N];
int vis[T][N];
double v;

bool check(double vel) {
    vez++;
    v = vel;
    return solve(0,0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    gol = (1<<n)-1;

    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> s[i];

    char trash;
    int k;
    cin >> trash >> k;
    k = 100-k;

    double l = 1;
    double r = 1e15;

    for(int i = 0; i < 90; i++) {
        double mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid;
    }

    cout << l << endl;
    return 0;
}

