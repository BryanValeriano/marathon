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
    int n; cin >> n;
    string s; cin >> s;

    int mini = 0;
    int at = 0;
    
    for(int i = 0; i < n; i++) {
        if(s[i] == '+') at++;
        else at--;
        mini = min(mini, at);
    }

    at = abs(mini);


    for(int i = 0; i < n; i++) {
        if(s[i] == '+') at++;
        else at--;
    }

    cout << at << endl;
    
    
    return 0;
}

