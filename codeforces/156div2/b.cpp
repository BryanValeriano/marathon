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
    string s;
    int x,y;
    x= y = 0;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'x') x++;
        else y++;
    }
    if(y > x) {
        y -= x;
        for(int i = 0; i < y; i++) cout << 'y';
    } else {
        x -= y;
        for(int i = 0; i < x; i++) cout << 'x';
    }
    cout << endl;
        

    return 0;
}

