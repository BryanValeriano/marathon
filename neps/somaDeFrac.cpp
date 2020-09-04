#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll lcd = (b*d)/__gcd(b,d);
    ll aa = (lcd/b*a);
    ll bb = (lcd/d*c);
    aa += bb;
    ll gcd = __gcd(lcd,aa);
    cout << (aa/gcd) << " " << (lcd/gcd) << endl;
    return 0;
}

