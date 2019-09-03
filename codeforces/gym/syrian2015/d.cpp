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

unordered_map<char,int> id;
char v[12];
ll qtd[10];

void pre() {
    id['A'] = 1; v[1] = 'A';
    id['H'] = 2; v[2] = 'H';
    id['I'] = 3; v[3] = 'I';
    id['M'] = 4; v[4] = 'M';
    id['O'] = 5; v[5] = 'O';
    id['T'] = 6; v[6] = 'T';
    id['U'] = 7; v[7] = 'U';
    id['V'] = 8; v[8] = 'V';
    id['W'] = 9; v[9] = 'W';
    id['X'] = 10; v[10] = 'X';
    id['Y'] = 11; v[11] = 'Y';

    for(int i = 1; i < 10; i++)
        qtd[i] = pow(11LL,i);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    pre();

    int tc; cin >> tc;
    while(tc--) {
        ll n;
        string s;
        cin >> n >> s;
        
        ll tot = 0;
        string as = "";

        if(s.size() < 9) 
            while(s.size() + as.size() <= 11 and tot + qtd[s.size() + as.size()] <= n) 
            tot += qtd[s.size() + as.size()], as += 'A';
        

        s = as + s;

        int fim = s.size() - 1;
        if(s.size() > 10) fim = s.size() - 9;

        ll at = tot;
        for(int i = fim; i >= 1; i--) 
            for(int j = v[id[s[i]]] + 1; j <= 11; j++) 
                if(at + qtd[i-1] <= n) s[at] = v[j], at += qtd[i-1];

        cout << s << endl;
    }
    return 0;
}

