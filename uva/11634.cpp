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

unordered_set<int> bag;

int main() {
    ios::sync_with_stdio(false);
    string s,t;
    cin >> s;

    while(s != "0") {
        bag.clear();
        ll x = stoi(s);
        while(!bag.count(x)) {
            bag.insert(x);
            x *= x;
            s = to_string(x);
            t = "";
            while(t.size() + s.size() < 8) t += '0';
            s = t+s;
            t = "";
            for(int i = 2; i < 6; i++) t += s[i];
            x = stoi(t);
        }
        cout << bag.size() << endl;
        cin >> s;
    }

    return 0;
}

