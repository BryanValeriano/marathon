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
    ios_base::sync_with_stdio(false);
    string s; int k;
    cin >> s >> k;
    reverse(s.begin(),s.end());
    int n = s.size();
    int z = 0;
    int y = 0;
    for(int i = 0; i < n and z < k; i++) {
        if(s[i] == '0') z++;
        else y++;
    }
    cout << (z == k? y : (z? n-1 : n)) << endl;
    return 0;
}

