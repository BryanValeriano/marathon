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

deque<char> v;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    char x;
    for(int i = 0; i < n; i++) {
        cin >> x;
        if(i&1 and n&1) v.push_front(x);
        else if(i&1 and !(n&1)) v.push_back(x);
        else if(!(i&1) and !(n&1))v.push_front(x);
        else v.push_back(x);
    }

    for(int i = 0; i < n; i++) 
        cout << v[i];

    cout << endl;

    return 0;
}

