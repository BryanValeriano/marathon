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
    string s; cin >> s;
    int n = s.size();
    int tent = 0;
    int solto, perLine;
    int flag = INF;
    int mais;
    while(true) {
        tent++;
        perLine = n/tent;
        if(n%tent != 0) perLine++;
        if(perLine > 20) continue;
        solto = abs((perLine*tent) - n); 
        if(perLine*tent > n)
            mais = 1;
        else mais = 0;
        break;
    }
    int track = 0;
    cout << tent << " " << perLine << endl;
    for(int i = 1; i <= tent; i++) {
        if(i == tent) {
            if(i <= solto) cout << "*";
            for(;track < n; track++) cout << s[track];
            cout << endl;
        }
        else {
            if(i <= solto) cout << "*";
            else mais = 0;
            for(int j = 0;j < (perLine - mais); track++, j++) cout << s[track];
            cout << endl;
        }
    }
    return 0;
}

