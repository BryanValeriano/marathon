#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int perolas = 0; int linhas = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'o') perolas++;
        else linhas++;
    }
    (perolas != 0 && linhas%perolas != 0)? cout << "NO" : cout << "YES";
    cout << endl;

    return 0;
}

