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
    int a[3], b[3];
    for(int i = 0; i < 3; i++)
        cin >> a[i];
    for(int i = 0; i < 3; i++)
        cin >> b[i];
    int x = 0, y = 0;
    for(int i = 0; i < 3; i++) {
        if(a[i] > b[i]) x++;
        else if(a[i] < b[i]) y++;
    }
    cout << x << " " << y << endl;

    return 0;
}

