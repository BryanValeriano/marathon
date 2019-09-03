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
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    cout << (a+b+c)*(a+b+c)-(a*a + c*c + e*e) << endl; 
    return 0;
}

