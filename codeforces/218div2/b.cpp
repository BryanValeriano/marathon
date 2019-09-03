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

int dois, tres, cinco;

int main() {
    ios::sync_with_stdio(false);
    ll a, b;
    cin >> a >> b;
    ll gcd = __gcd(a,b);

    a /= gcd;
    b /= gcd;

    while(a % 2 == 0) dois++, a /= 2;
    while(a % 3 == 0) tres++, a /= 3;
    while(a % 5 == 0) cinco++, a /= 5;
    while(b % 2 == 0) dois++, b /= 2;
    while(b % 3 == 0) tres++, b /= 3;
    while(b % 5 == 0) cinco++, b /= 5;
    
    cout << (a == b and b == 1? dois + tres + cinco : -1) << endl;

    return 0;
}

