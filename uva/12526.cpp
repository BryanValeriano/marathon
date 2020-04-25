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

const int T = 1e6+2;
const int N = 27;

int trie[T][N];
int vis[T][N];
int size[T];
int vis2[T];
bool isFinal[T];
int root, nodes,vez;
vector<string> v;

void createNode(int node, int x) {
    trie[node][x] = nodes++;
    vis[node][x] = vez;
    size[node]++;
}

void resetNode(int node) {
    size[node] = 0;
    vis2[node] = vez;
    isFinal[node] = 0;
}

void addWord(const string &s) {
    int pos = 0;
    int node = root;
    while(pos < s.size()) {
        int x = s[pos]-'a';
        if(vis2[node] != vez) resetNode(node);
        if(vis[node][x] != vez) createNode(node,x);
        node = trie[node][x];
        pos++;
    }
    if(vis2[node] != vez) resetNode(node);
    isFinal[node] = 1;
}

int countLetters(const string &s) {
    int pos = 0;
    int node = root;
    int ans = 0;
    while(pos < s.size()) {
        int x = s[pos]-'a';
        if(size[node] != 1 or isFinal[node]) ans++;
        node = trie[node][x];
        pos++;
    }

    return ans;
}

void reset() {
    v.clear();
    vez++;
    nodes = 1;
    size[root] = 10;
    vis2[root] = vez;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    while(cin >> n) {
        reset();
        for(int i = 0; i < n; i++) {
            string s; cin >> s;
            v.pb(s);
            addWord(s);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += countLetters(v[i]);
        }
        cout << fixed << setprecision(2) << (double)ans/(double)n << endl;
    }
    return 0;
}

