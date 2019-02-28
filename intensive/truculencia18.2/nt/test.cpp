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

const int n = 3e5;

int main() {
    ios::sync_with_stdio(false);
    cout << n << endl;
    int x = 1e7 + 1;
    int y = 1e6;
    for(int i = 0; i < n; i++) cout << ((y + i) % x) << " ";
    cout << endl;
    return 0;
}

