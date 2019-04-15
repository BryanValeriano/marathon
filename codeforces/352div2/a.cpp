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

int main() {
    ios::sync_with_stdio(false);
    string s;
    for(int i = 1; i <= 1010; i++) 
        s += to_string(i);
    int n; cin >> n;
    cout << s[n-1] << endl;

    return 0;
}

