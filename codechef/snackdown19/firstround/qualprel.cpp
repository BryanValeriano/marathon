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
const int T = 1e5 + 3;
vector<int> row;

bool cmp(const int &a, const int &b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc; 
    row.reserve(T);
    while(tc--) {
        int n, k; cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> row[i];
        sort(row.begin(), row.begin() + n, cmp);
        int gol = row[k-1];
        vector<int>::iterator last = upper_bound(row.begin() + (k-1), row.begin() + n, gol, greater<int>());
        cout << (last - row.begin()) << endl;
    }

    return 0;
}

