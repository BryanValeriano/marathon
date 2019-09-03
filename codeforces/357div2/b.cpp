#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
const int INF = 1e9;
int n;
int x = 1234567;
int y = 123456;
int z = 1234;

bool flag = false;

//void brute(int num) {
//    if(num == n) flag = true;
//    if(num > n or flag) return;
//    int a = n - num;
//    int d, e, f, g, h;
//    d = a % x;
//    e = a % y;
//    f = a % z;  
//    g = a % x + y;   
//    h = a % z + y;   
//    if(d == 0 or e == 0 or f == 0 or g == 0 or h == 0) flag = true;
//
//    brute(num + y);
//    brute(num + x);
//}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    //brute(0);
    for(int i = 0; i <= INF/x; i++) {
        for(int j = 0; j <= INF/y; j++) {
            int a = n - ((x*i) + (y*j));
            if(a == 0 or ((a > 0) and a % z == 0)) {
                flag = true;
                break;
            }
        }
    }
    cout << (flag? "YES" : "NO") << endl;
    return 0;
}

