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

const int T = 1e5 + 2;
ll acum[T];
ll v[T];
string s;
int n;

int main() {
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> v[i], acum[i] = v[i];
        acum[i] += acum[i-1];
    }
   
    cin >> s;
    ll at = 0;

    for(int i = 1; i <= n; i++) {
        if(s[i-1] == '1') {
            if(v[i]+at > acum[i-1]) at += v[i];
            else at = acum[i-1];
        }
    }

    cout << at << endl;

    return 0;
}

