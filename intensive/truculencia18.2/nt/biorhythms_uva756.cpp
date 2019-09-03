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

int p, e, i, c;
int yp, ye, yi;
int zp, ze, zi;

int x,y,d;

const int N = 23 * 28 * 33;

void gcd(int a, int b) {
    if(b == 0) { x = 1; y = 0; d = a; return; }
    gcd(b, a%b);
    int x1 = y;
    int y1 = x - (a/b) * y;
    x = x1;
    y = y1;
}

int chinese() {
    int x = p*yp*zp + e*ye*ze + i*yi*zi;
    return x % N;
}

int transform(int y, int mod) {
    int k = 0;
    gcd(y, mod);
    int z = x;
    while(x + k*mod/d < 0) k++;
    z += k*mod/d;
    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> p >> e >> i >> c;

    yp = N/23;
    ye = N/28;
    yi = N/33;
    
    zp = transform(yp,23);
    ze = transform(ye,28); 
    zi = transform(yi, 33);

    int cont = 0;
    while(p != -1 or e != -1 or i != -1 or c != -1) {
        p %= 23;
        e %= 28;
        i %= 33;
        int x = chinese();
        while(x <= c) x += N; 
        cout << "Case " << ++cont << ": the next triple peak occurs in " << x-c <<  " days." << endl;
        cin >> p >> e >> i >> c;
    }
    return 0;
}

