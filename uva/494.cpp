#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) _back
#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

bool hasWords(string s) {
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 'a' and s[i] <= 'z') return 1;
        if(s[i] >= 'A' and s[i] <= 'Z') return 1;
    }
    return 0;
}

bool hasWord(char s) {
    if(s >= 'a' and s <= 'z') return 1;
    if(s >= 'A' and s <= 'Z') return 1;
    return 0;
}

int funk(string s) {
    string x;
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        if(!hasWord(s[i])) {
            if(hasWords(x)) ans++;
            x = "";
        } else x += s[i];
    }
    return ans + hasWords(x);
}

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    while(getline(cin,s)) {
        cout << funk(s) << endl;
    }
    return 0;
}

