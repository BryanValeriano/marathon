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

const int T = 505;
bool v1[T][T];
bool v2[T][T];
int n,m;
int l[T];
int c[T];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> v1[i][j];

    bool ok;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> ok;
            if(ok ^ v1[i][j]) l[i]++, c[j]++;
        }
    }

    bool nice = 1;

    for(int i = 0; i < n; i++) 
        nice &= (!(l[i]&1));

    for(int i = 0; i < m; i++) 
        nice &= (!(c[i]&1));

    cout << (nice? "YES" : "NO") << endl;

    return 0;
}

