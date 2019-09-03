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
#define loop(x)    for (int i = 0;i < x;i++)
 
int main() {
    ios_base::sync_with_stdio(false);

    int p, n, x;
    cin >> p >> n >> x;
    ii cx = {x / p, x % p}, cl = {n / p, n % p};
    int d1 = cx.first + min(cx.second, 1 + p - cx.second);
    int d2 = cl.first + (cx.second != 0);
    int aux;
    d2 += abs(cx.first - cl.first) + min((aux = abs(cx.second - cl.second)), p - aux + 1);
    cout << min(d1, d2) << endl;
    return 0;
}

