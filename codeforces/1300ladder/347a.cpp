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
const int T = 100 + 3;
int row[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    for(int i = 0; i < n; i++)
        cin >> row[i];
    sort(row, row+n);
    cout << row[n-1] << " ";
    for(int i = 1; i < n-1; i++)
        cout << row[i] << " ";
    cout << row[0] <<endl;

    return 0;
}

