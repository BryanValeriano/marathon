#include <bits/stdc++.h>
using namespace std;

#define push push_back
#define pb push_back
#define pop pop_back
#define top back
#define mk make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector< pair<int,int> > vii;
const int INF = 0x3f3f3f3f;

const int T = 1e5 + 5;
vector<string> v[T][30];
vector<string> bag[T];
int n;

int ff(char x) {
    if(x == 'a') return 0;
    else if(x == 'e') return 1;
    else if(x == 'i') return 2;
    else if(x == 'o') return 3;
    else if(x == 'u') return 4;
}

ii f(string s) {
    int qtd = 0;
    int last = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u') qtd++, last = ff(s[i]);
    }

    return mk(qtd,last);
}

bool flag(int i) {
    return (bag[i].size() >= 2);
}

struct node {
    string um,dois,tres,quatro;
};

vector<node> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    string s;
    
    for(int i = 0; i < n; i++) {
        cin >> s;
        ii x = f(s);
        v[x.fi][x.se].push(s);
    }

    for(int i = 0; i < T; i++) {
        for(int j = 0; j < 30; j++) {
            if(!v[i][j].empty() and v[i][j].size()&1) {
                string x = v[i][j].top();
                v[i][j].pop();
                bag[i].push(x);
            }
        }
    }
             
    int h = 0;
    bool pqp = true;

    for(int k = 0; k < T and pqp; k++) {
        if(h == (T-1)) pqp = false;
        for(int i = h; i < T and flag(k); i++) {
            h = i;
            for(int j = 0; j < 30 and flag(k); j++) {
                while(v[i][j].size() >= 2 and flag(k)) {
                    string a = bag[k].top();
                    bag[k].pop();
                    string b = bag[k].top();
                    bag[k].pop();
                    string c = v[i][j].top();
                    v[i][j].pop();
                    string d = v[i][j].top();
                    v[i][j].pop();
                    ans.pb({a,b,c,d});
                }
            }
        }
    }

    for(int i = 0; i < T; i++) {
        while(!bag[i].empty()) {
            v[i][f(bag[i].top()).se].push(bag[i].top());
            bag[i].pop();
        }
    }
   
    int cont = 0;
    string xx[4];

    for(int i = 0; i < T; i++) { 
        for(int j = 0; j < 30; j++) {
            while(v[i][j].size() >= 2) {
                xx[cont++] = v[i][j].top();
                v[i][j].pop();
                xx[cont++] = v[i][j].top();
                v[i][j].pop();
                if(cont == 4) {
                    cont = 0;
                    ans.pb({xx[0],xx[1],xx[2],xx[3]});
                }
            }
        }
    }
        
    cout << ans.size() << endl;
    for(auto wtf : ans) 
        cout << wtf.um << " " << wtf.tres << '\n' << wtf.dois << " " << wtf.quatro << '\n';
    
    return 0;
}

