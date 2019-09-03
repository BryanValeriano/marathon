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
    int a1,a2,a3,b1,b2,b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    if(a2 + a3 <= a1 and max(b2,b3) <= b1) cout << "YES";
    else if(a2 + a3 <= b1 and max(b2,b3) <= a1) cout << "YES";
    else if(b2 + a3 <= b1 and max(a2,b3) <= a1) cout << "YES";
    else if(b2 + a3 <= a1 and max(a2,b3) <= b1) cout << "YES";
    else if(b2 + b3 <= a1 and max(a2,a3) <= b1) cout << "YES";
    else if(b2 + b3 <= b1 and max(a2,a3) <= a1) cout << "YES";
    else if(a2 + b3 <= b1 and max(b2,a3) <= a1) cout << "YES";
    else if(a2 + b3 <= a1 and max(b2,a3) <= b1) cout << "YES";
    else cout << "NO";
    cout << endl;
    return 0;
}

