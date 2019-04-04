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
string s,t;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s >> t;
    for(int i = 0; i < n; i++) {
        int x = s[i] - 'a';
        cout << x << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i++) {
        int x = t[i] - 'a';
        cout << x << " ";
    }
    cout << endl;
 
    string z = "alvuw";
    for(int i = 0; i < n; i++) {
        int x = z[i] - 'a';
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

