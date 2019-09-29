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
const int T = 1e5 + 3;

int n,k;
string s;
int next[T];
unordered_set<int> inis;
int t = 1;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> s;
    s += '$';

    char ok = s[0];
    char prox = (s.size() > t? s[t] : '#');

    for(int i = 0; i < s.size(); i++)
        if(s[i] == ok) inis.insert(i);


    while(inis.size() >= k) {
        t++;
        ok = prox;
        prox = (s.size() > t? s[t] : '#');

        vector<int> del;
        for(auto w : inis) if(s[w+t-1] != ok) del.pb(w);

        //cout << inis.size() << " " << del.size() << endl;

        if(inis.size() - del.size() < k) break;
        for(int i = 0; i < del.size(); i++) inis.erase(del[i]);
    }

    if(inis.size() < k) {
        cout << "NO IDEA" << endl;
    } else {
        for(int i = 0; i < t-1; i++) cout << s[i];
        cout << endl;
    }

    return 0;
}

