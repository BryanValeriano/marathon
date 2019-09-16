#include <bits/stdc++.h>
using namespace std;

#define pb	push_back
#define eb	emplace_back
#define mk	make_pair
#define fi	first
#define se	second
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 30;
int freq[T];
int need[T];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> s;
    int tot = s.size();
    int wat = tot/2;
    if(tot&1) { cout << "NO" << endl; return 0; }
    for(int i = 0; i < s.size(); i++) {
        freq[s[i]-'a']++;
        if(freq[s[i]-'a'] > wat) { cout << "NO" << endl; return 0; }
    }
    cout << "YES" << endl;
    return 0;
}

