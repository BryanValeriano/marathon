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
const int T = 1e5 + 3;
int v[T];

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;
    if(s[0] == 'G') v[0] = 1;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == 'G' and s[i-1] == 'S') v[i] = 1;
        if(s[i] == 'G' and s[i-1] == 'G') v[i] = v[i-1] + 1;
        if(s[i] == 'S') v[i] = 0;
    }
    for(int i = 0; i < s.size(); i++) {


     
    //for(int i = 0; i < s.size(); i++)
    //    cout << v[i] << " ";
    //cout << endl;
    

    return 0;
}

