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

int n;

int dif(int a, int b) {
    if((a == 1 or b == 1) and (a == 2 or b == 2)) return 3;
    if((a == 2 or b == 2) and (a == 3 or b == 3)) return 1;
    if((a == 1 or b == 1) and (a == 3 or b == 3)) return 2;
}

bool joga(int i, int last, int at) { 
    if(i >= n) return true;
    int x; cin >> x;
    if(x != last and x != at) return false;

    if(i == 0) last = 3;
    else if(at != x) last = dif(at,x);
    else last = dif(at,last);
    at = x;

    return (true & joga(i+1,last,at));
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    if(joga(0,1,2)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

