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

const int T = 21;

int n,m;
double p[T];
double a[T];
double b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int cont = 0;

    cout << fixed << setprecision(6);

    while(n or m) {
        int bag[n];
        b = 0;
        for(int i = 0; i < n; i++) bag[i] = (i < m? 0 : 1);
        for(int i = 0; i < n; i++) cin >> p[i];
        memset(a, 0, sizeof a);

        do {
            double k = 1;
            for(int i = 0; i < n; i++) k = k * (!bag[i]? p[i] : (1 - p[i]));
            for(int i = 0; i < n; i++) if(!bag[i]) a[i] += k;
            b += k;
        } while(next_permutation(bag, bag+n));

        cout << "Case " << ++cont << ":" << endl;
        for(int i = 0; i < n; i++) cout << a[i]/b << endl;
        cin >> n >> m;
    }


    return 0;
}

