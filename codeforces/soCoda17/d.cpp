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

struct Trie {
    int cnt, word;
    map<char,Trie> m;

    Trie() {
        word = cnt = 0;
        m.clear();
    }

    void add(const string &s, int i) {
        cnt++;
        if(i == s.size()) {
            word++;
            return;
        }
        if(!m.count(s[i])) m[s[i]] = Trie();
        m[s[i]].add(s,i+1);
    }

    bool find(const string &s, int i, bool pulo) {
        if(!cnt) {
            if(pulo) return 0;
            pulo = 1;
        }
        if(i == s.size()) return (pulo and word);

        cout << s[i] << " " << i << " " << pulo << endl;

        if(!m.count(s[i])) {
            if(pulo) return 0;
            for(auto tent : m)
                if(m[tent.fi].find(s,i+1,1)) return 1;
            return 0;
        }

        return m[s[i]].find(s,i+1,pulo);
    }

    void remove(const string &s, int i) {
        cnt--;
        word--;
        if(i == s.size()) return;
        m[s[i]].remove(s,i+1);
    }
};

vector<string> v;
set<string> corn;

int main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    Trie T;

    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        v.pb(s);
        T.add(s,0);
    }

    for(auto s : v) {
        T.remove(s,0);
        if(T.find(s,0,0)) corn.insert(s);
        cout << endl;
        T.add(s,0);
    }


    //for(int i = 0; i < m; i++) {
    //    string s; cin >> s;
    //    if(corn.count(s)) { cout << "YES" << endl; continue; }
    //    cout << (T.find(s,0,0)? "YES" : "NO") << endl;
    //}

    return 0;
}

