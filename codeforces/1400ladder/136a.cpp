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
const int T = 110;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int aux;
    for(int i = 1; i <= n; i++) {
        cin >> aux;
        v[aux] = i;
    }
    for(int i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << endl;

    return 0;
}

