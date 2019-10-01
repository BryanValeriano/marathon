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

const int T = 1002;

int zero[T];
int um[T];
int n,m;
map<string,string> id;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    string lixo;
    string op;
    string val;
    while(n--) {
        string x; cin >> x;
        cin >> lixo;
        cin >> op;
        if(op == "?") {
            cin >> op >> val;
            eval(op,val);
        }
    
    
    return 0;
}

