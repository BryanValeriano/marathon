#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define loop(x) for (int i = 0;i < x;i++)
#define each(x, xs) for (auto& x : xs)
#define iter(a) a.begin(), a.end()

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e6 + 5;
bool ok[N];
map<string, string> trad;

struct Trie {
    int cnt, word;
    map<char, Trie> m;
    Trie() {
	word = cnt = 0;
	m.clear();
    }

    void add (const string &s, int i) {
	cnt++;
	if(i == (int) s.size()) { word++; return; }
	if(!m.count(s[i])) m[s[i]] = Trie();
	m[s[i]].add(s, i+1);
    }

    void check(const string &s, int i, const int &ini) {
        if(word) ok[ini-i+1] = 1; 
        if(!m.count(s[i])) return;
        m[s[i]].check(s,i+1,ini);

    }

    int max_prefix(const string &s, int i) {
	if(i == (int)s.size() or !m.count(s[i])) return word > 0 and ok[i]? i-1 : -INF;
	return max(word > 0 and ok[i]? i-1 : -INF, m[s[i]].max_prefix(s, i+1));
    }
} T;

Trie G;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >>n;
    string s, t; 
    getline(cin, s);

    for(int i = 0; i < n; i++) {
	getline(cin, s);
	getline(cin, t);
	trad[s] = t;
	T.add(s,0);
        reverse(s.begin(),s.end());
        G.add(s,0);
    }

    getline(cin, s);
    ok[s.size()] = 1;
    for(int i = s.size()-1; i >= 0; i--) {
        string aux;
        if(!ok[i+1]) continue;
        for(int j = i; j >= 0 and i-j <= 50; j--) aux += s[j];
        G.check(aux,0,i);
    }

    int i = 0, j;
    string ans;

    while(i < s.size()) {
        if(i != 0) ans += " ";
	j = T.max_prefix(s, i);
	t = "";
	for(int k = i; k <= j; k++) t += s[k];
        ans += trad[t];
	i = j+1;
    }
    cout << ans << endl;
    return 0;
}
 
