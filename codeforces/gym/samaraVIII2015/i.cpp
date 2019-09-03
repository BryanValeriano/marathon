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
#define loop(x) for(int i = 0;i < x;i++)
 
int main() {
    ios_base::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;
    string dir;
    cin >> dir;
    int n;
    cin >> n;
    string name, win;
    int a, b, t = INF;
    bool p = dir == "UP" or dir == "DOWN";
    int vel = (dir == "DOWN" or dir == "LEFT" ? -1 : 1);
    if (p) swap(x, y);
    loop(n) {
        cin >> name >> a >> b;
        if (!p) swap(a, b);
        int delx = abs(x - a), dely = abs(y - b);
        int ta = delx / 2 + (delx & 1);
        y += ta * vel;
        int va = 2 * (b > y ? -1 : 1);
        dely = abs(b - y);
        ta += dely / abs(va - vel) + (dely % abs(va - vel) != 0);
        if (ta < t) {
            t = ta;
            win = name;
        }
    }
    cout << win << endl;
    
    return 0;
}

