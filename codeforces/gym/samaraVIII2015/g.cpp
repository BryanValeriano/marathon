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

    int n;
    cin >> n;
    string s;
    int x = -1, aux;
    stack<int> g;
    loop(2 * n) {
        cin >> s >> aux;
        if (s == "in") {
            if (x != -1) {
                g.push(x);
                cout << x << " " << aux << endl;
            }
            x = aux;
        }
        else {
            if (g.empty()) x = -1;
            else {
                x = g.top();
                g.pop();
            }
        }
    }
    return 0;
}

