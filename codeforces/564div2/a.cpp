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
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b+c) cout << "+";
    else if(a == b and !c) cout << "0";
    else if(b > a+c) cout << "-";
    else cout << "?";
    cout << endl;
    return 0;
}

