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

string solve(int n) {
    int ans = 0;
    for(int i = 1; i < n; i++) 
        if(n % i == 0) ans += i;
    if(ans < n) return "DEFICIENT";
    if(ans > n) return "ABUNDANT";
    else return "PERFECT";
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cout << "PERFECTION OUTPUT" << endl;
    cin >> n;
    while(n) {
        cout << right << setw(5) << n;
        cout << "  " << solve(n) << endl;
        cin >> n;
    }
    cout << "END OF OUTPUT" << endl;
    return 0;
}

