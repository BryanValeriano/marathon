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
const int N = 3e5 + 3;
string row[N];
ll row1[N];
map<string,ll> id;

struct Trie {
    int cnt, word;
    map<char,Trie> m;

    Trie () {
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

    string search(const string &s, int i) {
        cnt--;
        if(i == s.size()) {
            word--;
            return "";
        }
        if(m[s[i]].cnt >= 1) {
            return s[i] + m[s[i]].search(s,i+1);  
        } else {
            char out;
            if(s[i] == '0') out = '1'; 
            else out = '0';
            return out + m[out].search(s,i+1);
        }
    }
} T;

int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string s;
    ll aux;
    for(int i = 0; i < n; i++) {
        cin >> row1[i];
        s = bitset<32>(row1[i]).to_string(); 
        row[i] = s;
    }
    for(int i = 0; i < n; i++) {
        cin >> aux;
        s = bitset<32>(aux).to_string(); 
        T.add(s,0);
        id[s] = aux;
    }
    for(int i = 0; i < n; i++) {
        string x = T.search(row[i],0);
        ll aux =  row1[i] ^ id[x]; 
        cout << aux << " ";
    }
    cout << endl;
    return 0;
}

