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
const int T = 2e5+3;
ll ve[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    cin >> ve[0];
    for(int i = 1; i < n; i++) {
        cin >> ve[i];
        ve[i] += ve[i-1];
    }
    ll mid = ve[n-1]/2;
    if(ve[n-1] % 2 != 0) mid++;
    for(int i = 0; i < n; i++)
        if(ve[i] >= mid) { cout << i+1 << endl; break; }


    return 0;
}

