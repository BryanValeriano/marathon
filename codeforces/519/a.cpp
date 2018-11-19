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
int row[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int maxi = 0;
    int a = 0;
    int b = 0;
    for(int i = 0; i < n; i++) {
        cin >> row[i];
        maxi = max(maxi, row[i]);
        a += row[i];
    }
    for(int i = 0; i < n; i++) {
        b += maxi - row[i];
    }
    while(a >= b) {
        b += n;
        maxi++;
    }
    cout << maxi << endl;
    

    return 0;
}

