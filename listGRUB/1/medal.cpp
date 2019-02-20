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
    int a,b,c,x,y,z;
    cin >> a >> b >> c;
    if(a < b and a < c) x = 1;
    else if(a < b or a < c) y = 1;
    else z = 1;
    if(b < a and b < c) x = 2;
    else if(b < a or b < c) y = 2;
    else z = 2;
    if(c < a and c < b) x = 3;
    else if(c < a or c < b) y = 3;
    else z = 3;
    cout << x << endl << y << endl << z << endl;
    return 0;
}

