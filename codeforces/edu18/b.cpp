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

vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n;
    for(int i = 1; i <= n; i++) v.pb(i);

    cin >> k;
    int x;
    int last = 0;
    int tam = n;
    for(int i = 0; i < k; i++) {
        cin >> x;
        int index = (last + x) % tam;
        cout << v[index] << " ";
        v.erase(v.begin() + index);
        last = index;
        tam--;
    }
    cout << endl;
    return 0;
}

