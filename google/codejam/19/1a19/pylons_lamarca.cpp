#include <bits/stdc++.h>
using namespace std;
 
//freopen("file_name.in", "r", stdin);
//freopen("file_name.out", "w", stdout);
 
#define fr(i,n) for(int i=0;i<n;i++)
#define frr(i,a,b) for(int i =a;i<=b;i++)
 
typedef long long ll;
 
#define eb emplace_back
 
#define all(v) (v).begin(),(v).end()
 
#define fi first
#define se second
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
//-DBL_MAX
//__builtin_popcountll(ll x) - __builtin_popcount(int x)
 
#define prin(a) cout << #a << " = " << (a) << endl
#define prinv(v) {cout << #v << " = "; for(auto it : v) cout << it << " "; cout << endl;}
#define ppal(a)  cout << #a << endl
 
const int N = -1;
 
clock_t ts;
 
double tempo(){
    return 1.*(clock()-ts)/CLOCKS_PER_SEC;
}
 
bool pos(int ui, int uj, int i, int j){
    return ui!=i and j!=uj and ui+uj!=i+j and ui-uj!=i-j;
}
 
int main(){
 
    srand(time(0));
 
    int t;
    cin >> t;
   
    fr(tt,t){
   
        ts = clock();
        int n, m;
        scanf("%d %d", &n, &m);
       
        printf("Case #%d: ", tt+1);
       
        while(tempo() < 15./t){
            vector<vector<int>> vis(n,vector<int>(m));
           
            vector<pii> cand;
            vector<pii> jogadas;
           
            int ui = 100, uj = 200;
            //faco jogada e atualizo ult e ponho no vet jogadas
            fr(nm,n*m){
                fr(i,n){
                    fr(j,m){
                        if(!vis[i][j] and pos(ui,uj,i,j)) cand.eb(i,j);
                    }
                }
               
                if(cand.empty()) goto prox;
               
                int ij = rand()%cand.size();
               
                jogadas.eb(cand[ij].fi,cand[ij].se);
                cand.clear();
               
                tie(ui,uj) = jogadas.back();
                vis[ui][uj] = 1;
            }
           
            if(jogadas.size()<n*m) continue;
           
            puts("POSSIBLE");
           
            for(auto par : jogadas){
                printf("%d %d\n", par.fi+1,par.se+1);
            }
           
            goto fim;
           
            prox:
            continue;
        }
       
        puts("IMPOSSIBLE");
       
        fim:
        continue;
    }
   
    return 0;
}
