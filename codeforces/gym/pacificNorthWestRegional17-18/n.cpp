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

int main() {
    ios_base::sync_with_stdio(false);
    string s; cin >> s;

    for(int i = 0; i < s.size(); i++) {
        string ok = "";
        for(int j = i; j < s.size(); j++) {
            ok += s[j];
            if((j-i)&1) {
                string ko = ok;
                reverse(ko.begin(), ko.end());
                if(ok == ko) { cout << "Or not." << endl; return 0; }
            }
        }
    }
    cout << "Odd." << endl;
    return 0;
}

