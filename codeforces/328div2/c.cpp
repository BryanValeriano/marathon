#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

ull mdc(ull a, ull b) {
    return(b == 0 ? a : mdc(b, a%b));
}

int main() {
    ios::sync_with_stdio(false);
    ull t, a, b;
    cin >> t >> a >> b; 
    if(a == b) {
        cout << 1 << "/" << 1 << endl;
        return 0;
    }
    ull mini = min(a, b);
    ull mmc = (a/mdc(a,b)) * b;
    ull freq = t/mmc;
    freq += ((mini - 1)*freq);
    ull resp = 0;
    resp += freq  + (mini - 1); 
    ull gcd = mdc(resp,t);
    resp /= gcd;
    t /= gcd;
    cout << resp << "/" << t <<  endl;

    return 0;
}

