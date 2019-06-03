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
    double car,cow,show;
    double ans;
    cout << fixed << setprecision(5);

    while(cin >> cow) {
        cin >> car >> show;
        ans = (cow/(car+cow)) * car/(car+cow-show-1);
        if(car-1) ans += (car/(car+cow)) * (car-1)/(car+cow-show-1);
        cout << ans << endl;
    }
        

    return 0;
}

