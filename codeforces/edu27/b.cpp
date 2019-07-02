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

vector<string> v;

int main() {
    ios::sync_with_stdio(false);

    for(int i = 0; i <= 999999; i++) {
        string x = to_string(i); 
        bool flag = 0;
        while(x.size() < 6) x += '0', flag = 1;
        if(flag) reverse(x.begin(),x.end());

        int a = 0;
        int b = 0;
        for(int j = 0; j < 3; j++) {
            a += x[j];
            b += x[j+3];
        }
        if(a==b) v.pb(x);
    }

    string s; cin >> s; 
    int ans = INF;
    for(int i = 0; i < v.size(); i++) {
        int k = 0;
        for(int j = 0; j < 6; j++) k += (s[j] != v[i][j]); 
        ans = min(ans,k);
    }
    cout << ans << endl;

    return 0;
}

