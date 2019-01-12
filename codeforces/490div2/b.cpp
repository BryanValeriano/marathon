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

string reverse(string x, int y) {
    string t;
    for(int i = y-1; i >= 0; i--)
        t += x[i];
    for(int i = y; i < x.size(); i++)
        t += x[i];
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    int n; string s;
    cin >> n >> s;
    for(int i = 2; i <= n; i++)  {
        if(n % i == 0) {
            s = reverse(s, i);
            //cout << s << endl;
        }
    }
    cout << s << endl;


    return 0;
}

