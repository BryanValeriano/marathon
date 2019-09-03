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
const int T = 1e3 + 5;
int row[T];

int main() {
    ios::sync_with_stdio(false);
    string s; cin >> s;
    for(int i = 0; i < s.size() - 1; i++) { 
        if(s[i] != s[i+1]) cout << 1 << " ";
        else cout << 0 << " ";
    } 
    int fim = s.size() - 1;
    if(s[fim] == 'a') cout << 1;
    else cout << 0;
    cout << endl;

    return 0;
}

