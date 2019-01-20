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

int freq[30];

int quant() {
    int ans = 0;
    for(int i = 0; i < 30; i++) if(freq[i] > 0) ans++;
    return ans;
}

void print() {
    for(int i = 0; i < 30; i++) {
        if(freq[i]) {
            char x = i + 'a';
            while(freq[i]) {
                cout << x;
                freq[i]--;
            }
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        string s;
        cin >> s;
        memset(freq, 0, sizeof freq);
        for(int i = 0; i < s.size(); i++) freq[s[i] - 'a']++;
        if(quant() > 1) 
            print();
        else cout << -1 << endl;
    }
    return 0;
}

