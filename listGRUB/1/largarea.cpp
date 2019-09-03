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
    int a,b; cin >> a >> b;
    int c,d; cin >> c >> d;
    a = a*b;
    b = c*d;
    if(a == b){ cout << "Empate" << endl; return 0; }
    cout << (a > b? "Primeiro" : "Segundo") << endl;

    return 0;
}

