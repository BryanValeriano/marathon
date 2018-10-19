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
int row[T];

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i = 0; i < n; i++)
            cin >> row[i];
        int sum = row[0];
        int last = 0;
        int dia = 0;
        while(last < n) {
            if(last == n-1) break;
            dia++;
            int lastsum = sum;
            for(int i = 0; i < lastsum && last < n; i++)
                sum += row[++last];
        }
        cout << dia << endl;
    }

    return 0;
}

