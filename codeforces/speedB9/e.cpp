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

const int T = 12;

vector<string> ans;
string in[T];
int b[T];
int c[T];
int n;

int bull(string x, string y) {
    int z = 0;
    for(int i = 0; i < 4; i++)
        if(x[i] == y[i]) z++;
    return z;
}

int cow(string x, string y) {
    int z = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(x[i] == y[j] and i != j) z++;
    return z;
}

bool check(string s) {
    for(int i = 0; i < n; i++) 
        if(bull(s,in[i]) != b[i] or cow(s,in[i]) != c[i]) return 0;
    return 1;
}

void gen() {
    string x = "0000";
    for(int i = 0; i <= 9; i++) {
        x[0] = '0'+i;
        for(int j = 0; j <= 9; j++) {
            if(i == j) continue;
            x[1] = '0'+j;
            for(int p = 0; p <= 9; p++) {
                if(p == j or p == i) continue;
                x[2] = '0'+p;
                for(int k = 0; k <= 9; k++) {
                    if(k == p or k == j or k == i) continue;
                    x[3] = '0'+k; 
                    if(check(x)) ans.pb(x);
                }
            }
        }
    }
}

 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;

    for(int i = 0; i < n; i++) 
        cin >> in[i] >> b[i] >> c[i];
    
    gen();

    if(ans.size() > 1) cout << "Need more data" << endl;
    else if(ans.size() == 1) cout << ans[0] << endl;
    else cout << "Incorrect data" << endl;

    return 0;
}

