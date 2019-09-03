#include "bits/stdc++.h"
using namespace std;

#define pb push_back

#define fr(i,n) 	for(int i=0;i<n;i++)
#define frr(i,n)	for(int i=1;i<=n;i++)

#define ms(x,i)	memset(x,i,sizeof(x))
#define dbg(x)	cout << #x << " = " << x << endl
#define all(x)	x.begin(),x.end()
#define fst first
#define snd second

#define gnl cout << endl
#define olar cout << "olar" << endl
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL) 

typedef vector<int> vi;
typedef vector<pair<int,int>> vii;

const int INF = 0x3f3f3f3f;

int n;
string cara;
int sz;

int cost[30][30],transf[30][30];
int memo[220][220][26];
int quem[220][220];

vii possibilities[26];

int calc(string x){
    reverse(all(x));
    int base=1;
    int sum = 0;
    for(auto y : x){
        sum+=base*(y-'0');
        base*=10;
    }
    return sum;
}

int pd(int i, int j,int who){

    if(i>j)     return INF;
    if(i==j){
        if(who==cara[i]-'a')    return 0;
        return INF;
    }

    int& pdm = memo[i][j][who];
    if(pdm!=-1) return pdm;

    pdm = INF;

    for(int k = i;k<j;k++){
        for(auto x : possibilities[who])
            pdm = min(pdm, cost[x.fst][x.snd] + pd(i,k,x.fst) + pd(k+1,j,x.snd) );
    }

    return pdm;

}

void go(){

    vi symb;
    fr(i,26)
        possibilities[i].clear();

    ms(transf,-1);
    ms(cost,-1);

    fr(i,n){
        char x; cin >> x;
        symb.pb(x-'a');
    }

    fr(i,n){
        fr(j,n){
            string s; cin >> s;
            int to = s[s.size()-1] - 'a';
            s.pop_back();
            s.pop_back();
            int amt = calc(s);
            int left = symb[i];
            int right = symb[j];
            transf[left][right]=to;
            cost[left][right]=amt;
            possibilities[to].pb({left,right});
        }
    }

    int q; cin >> q;

    while(q--){

        cin >> cara;
        sz=cara.size();

        ms(memo,-1);

        int ans = INF; 
        char bago = 'x';

        fr(i,symb.size()){
            int fulano = symb[i];
            if(pd(0,sz-1,fulano)<ans){
                ans = pd(0,sz-1,fulano);
                bago=fulano+'a';
            }
        }

        cout << ans << "-" << bago << endl;
 
    }


}

int main(){

	fastio;
    int clk = 0;
    while(cin >> n){
        if(!n)  break;
        if(clk++!=0)    gnl;
        go();
    }
}
