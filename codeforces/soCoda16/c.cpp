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

unordered_map<string,int> freq;
vector<string> v;
int n;

void update(string s, int op) {
    for(int i = 0; i < s.size(); i++) {
        string tmp;
        for(int j = i; j < s.size(); j++) {
            tmp += s[j];
            freq[tmp] += op;
        }
    }
}

string minSub(string s) {
    int ans = INF;
    string x;

    for(int i = 0; i < s.size(); i++) {
        string tmp;
        for(int j = i; j < s.size(); j++) {
            tmp += s[j];
            if(freq[tmp] == 0 and ans > (int)tmp.size())
                ans = (int)tmp.size(), x = tmp;
        }
    }

    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        v.pb(s);
        update(s,1);
    }

    for(string s : v) {
        update(s,-1);
        cout << minSub(s) << endl;
        update(s,1);
    }

    return 0;
}

