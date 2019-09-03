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
string s1, s2;
double gol;
double tot;
double foi;

void solve(int i, int track) {
    if(i == s2.size()) {
        tot++;
        if(track == gol) foi++;
        return;
    }
    if(s2[i] != '?') {
        if(s2[i] == '+') track++;
        else track--;
        solve(i+1, track);
    } else {
        solve(i+1, track - 1);
        solve(i+1, track + 1);
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i] == '+') gol++;
        else gol--;
    }
    solve(0,0);
    cout << fixed << setprecision(9) << foi/tot << endl;

    return 0;
}

