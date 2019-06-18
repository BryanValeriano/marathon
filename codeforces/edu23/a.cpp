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
    int a,b,x,y,fa,fb;
    cin >> a >> b >> fa >> fb >> x >> y;

    fa = abs(fa-a);
    fb = abs(fb-b);

    bool um = false;
    bool dois = false;
    
    if(fa == 0 or fa%x == 0) um = 1;
    if(fb == 0 or fb%y == 0) dois = 1;

    if(um and dois) um &= (!(abs(fa/x - fb/y)&1));

    cout << (um and dois? "YES" : "NO") << endl;

    return 0;
}

